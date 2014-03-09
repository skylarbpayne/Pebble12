#include "Pebble12.h" //This will contain paths for the marks on the analog watch face.
#include "arcs.h"
#include "string.h"
#include "stdlib.h"

Layer* analog_face_layer;
Layer* hands_layer;

Layer* header_layer;
TextLayer* text_time_layer;
char time_buffer[] = "00:00";
TextLayer* date_layer;
TextLayer* num_layer;
char date_buffer[] = "xxxxxx";
char num_buffer[] = "0000";

static GPath* minute_hand; //Will be used to store shape of minute hand
static GPath* hour_hand; //Same ^^ but for hour hand
static GPath* tick_paths[NUM_CLOCK_TICKS]; //stores all positions of marks on analog face

Window* window;


typedef struct {
        int start_day;
        int end_day;
        int start_time;
        int end_time;
        char *title;
} Event;

typedef struct {
  Event *array;
  size_t used;
  size_t size;
} Array;

Array events;

//ALWAYS USE SIZE 48, because that's a lot.
void initArray(Array *a, size_t initialSize) {
  a->array = (Event *)malloc(initialSize * sizeof(Event));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, Event element) {
  if (a->used == a->size) {
    a->size *= 2;
   // a->array = (Event *)realloc(a->array, a->size * sizeof(Event)); //THIS SHIT NEEDS TO BE FIXED
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}


void removeElement(Array *a, Event e) {
        unsigned int i = 0;

        while(i < a->used) {
                if(a->array[i].start_day == e.start_day &&
                        a->array[i].end_day == e.end_day &&
                        a->array[i].start_time == e.start_time &&
                        a->array[i].end_time == e.end_time && strcmp(a->array[i].title,e.title) ==0 )
                {
                        unsigned int k = i + 1;
                        while(k < a->used) {
                                a->array[k-1] = a->array[k];
                                k++;
                        }
                        a->used--;
                        return;
                }
                i++;
        }
}

void out_sent_handler(DictionaryIterator *sent, void *context) {
   // outgoing message was delivered
 }


 void out_failed_handler(DictionaryIterator *failed, AppMessageResult reason, void *context) {
   // outgoing message failed
 }


 void in_received_handler(DictionaryIterator *received, void *context) {
         APP_LOG(APP_LOG_LEVEL_DEBUG, "We recieved a message!");

   // incoming message received
          // Check for fields you expect to receive
          Tuple *addOrRem = dict_find(received, 1);
          Tuple *sDay = dict_find(received, 2);
          Tuple *eDay = dict_find(received, 3);
          Tuple *sTime = dict_find(received, 4);
          Tuple *eTime = dict_find(received, 5);
          Tuple *tit = dict_find(received, 6);

        int addOrRemove = (int) addOrRem->value->data[0];
        int startDay = (int) sDay->value->int32;
        int endDay = (int) eDay->value->int32;
        int startTime = (int) sTime->value->int32;
        int endTime = (int) eTime->value->int32;
        char *title = tit->value->cstring;

          // Add or remove from local repository
          Event e = {startDay,endDay,startTime,endTime,title};
          if (addOrRemove) {
                insertArray(&events,e);
          } else {
                removeElement(&events,e);
          }

}


 void in_dropped_handler(AppMessageResult reason, void *context) {
   // incoming message dropped
 }


static void header_update_proc(Layer* layer, GContext* ctx) {
  time_t now = time(NULL);
  struct tm* t = localtime(&now);

  strftime(date_buffer, sizeof(date_buffer), "%a", t);
  text_layer_set_text(date_layer, date_buffer);
  strftime(num_buffer, sizeof(num_buffer), "%d", t);
  text_layer_set_text(num_layer, num_buffer);

  strftime(time_buffer, sizeof(time_buffer), "%I:%M", t);
  graphics_context_set_fill_color(ctx, GColorBlack);
  graphics_fill_rect(ctx, layer_get_bounds(layer), 0, GCornerNone);
  text_layer_set_text(text_time_layer, time_buffer);
}

static void analog_face_update_proc(Layer* layer, GContext* ctx) {
  graphics_context_set_fill_color(ctx, GColorBlack);
  GRect bounds = layer_get_bounds(layer);
  // int r = (bounds.size.w < bounds.size.h ? bounds.size.w : bounds.size.h) / 2;
  graphics_draw_circle(ctx, grect_center_point(&bounds), 70);
  
  for(int i = 0; i < NUM_CLOCK_TICKS; ++i)
    gpath_draw_filled(ctx, tick_paths[i]);
  
  //graphics_draw_arc(ctx, grect_center_point(&bounds), 70, 4, angle_90 / 2, angle_180 / 2, GColorBlack);
}

static void hands_update_proc(Layer* layer, GContext* ctx) {
  GRect bounds = layer_get_bounds(layer); //This will NOT be the whole clock face... Just where the analog piece lives
  const GPoint center = grect_center_point(&bounds); //Center of clock face
  const int16_t lim_dim = (bounds.size.w < bounds.size.h ? bounds.size.w : bounds.size.h); //we'll use smaller dimension as radius for second hand
  const int16_t second_hand_length = lim_dim / 2;
  GPoint second_hand;
  time_t now = time(NULL);
  struct tm* t = localtime(&now);

  int32_t second_angle = TRIG_MAX_ANGLE * t->tm_sec / 60; //Note: TRIG_MAX_ANGLE is 360 degrees or 2pi rad; also, 0 degrees is at 12th hour!
  //sin/cos seem swapped because of the shift (see comment above). Also, sin/cos move ccw ->  accounts for the negative sign.
  second_hand.y = (int16_t)(-cos_lookup(second_angle) * (int32_t)second_hand_length / TRIG_MAX_RATIO) + center.y;
  second_hand.x = (int16_t)(sin_lookup(second_angle) * (int32_t)second_hand_length / TRIG_MAX_RATIO) + center.x;

  graphics_context_set_stroke_color(ctx, GColorBlack);
  graphics_context_set_fill_color(ctx, GColorBlack);

  graphics_draw_line(ctx, second_hand, center);
  
  gpath_rotate_to(minute_hand, TRIG_MAX_ANGLE * t->tm_min / 60);
  gpath_draw_filled(ctx, minute_hand);

  gpath_rotate_to(hour_hand, (TRIG_MAX_ANGLE * (((t->tm_hour % 12) * 6) + (t->tm_min / 10))) / (12 * 6));
  gpath_draw_filled(ctx, hour_hand);

  graphics_context_set_fill_color(ctx, GColorWhite);
  graphics_fill_rect(ctx, GRect(bounds.size.w / 2 - 1, bounds.size.h / 2 - 1, 3, 3), 0, GCornerNone);
}

static void handle_second_tick(struct tm* tick_time, TimeUnits units_changed) {
  if(units_changed & MINUTE_UNIT) {
    layer_mark_dirty(header_layer);
  }
  if(units_changed & HOUR_UNIT) {
    //Grab events?
  }
  layer_mark_dirty(analog_face_layer);
}

static void window_load(Window* window) {
  Layer* window_layer = window_get_root_layer(window);

  analog_face_layer = layer_create(GRect(0, 20, 144, 148)); //CHANGE THIS TO LIMIT WHERE THE ANALOG CLOCK GOES!!!
  layer_set_update_proc(analog_face_layer, analog_face_update_proc);
  layer_add_child(window_layer, analog_face_layer);

  hands_layer = layer_create(layer_get_bounds(analog_face_layer));
  layer_set_update_proc(hands_layer, hands_update_proc);
  layer_add_child(analog_face_layer, hands_layer);

  header_layer = layer_create(GRect(0, 0, 144, 20));
  layer_set_update_proc(header_layer, header_update_proc);
  layer_add_child(window_layer, header_layer);
  
  text_time_layer = text_layer_create(GRect(0, 0, 72, 20));
  text_layer_set_text_alignment(text_time_layer, GTextAlignmentCenter);
  text_layer_set_text(text_time_layer, time_buffer);
  text_layer_set_text_color(text_time_layer, GColorWhite);
  text_layer_set_background_color(text_time_layer, GColorBlack);

  date_layer = text_layer_create(GRect(72, 0, 52, 20));
  text_layer_set_text_alignment(date_layer, GTextAlignmentCenter);
  text_layer_set_text_color(date_layer, GColorWhite);
  text_layer_set_background_color(date_layer, GColorBlack);

  num_layer = text_layer_create(GRect(124, 0, 20, 20));
  text_layer_set_text_alignment(num_layer, GTextAlignmentCenter);
  text_layer_set_text_color(num_layer, GColorWhite);
  text_layer_set_background_color(num_layer, GColorBlack);
 
  layer_add_child(header_layer, text_layer_get_layer(text_time_layer));
  layer_add_child(header_layer, text_layer_get_layer(date_layer));
  layer_add_child(header_layer, text_layer_get_layer(num_layer));
}

static void window_unload(Window* window) {
  layer_destroy(analog_face_layer);
  layer_destroy(hands_layer);
  layer_destroy(header_layer);
  text_layer_destroy(text_time_layer);
  text_layer_destroy(date_layer);
  text_layer_destroy(num_layer);
}

static void init(void) {
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
      .load = window_load,
	.unload = window_unload,
	});
  
  minute_hand = gpath_create(&MINUTE_HAND_POINTS);
  hour_hand = gpath_create(&HOUR_HAND_POINTS);

  initArray(&events,48);


  for(int i = 0; i < NUM_CLOCK_TICKS; ++i)
    tick_paths[i] = gpath_create(&ANALOG_BG_POINTS[i]);
  
  const bool fullscreen = true;
  window_set_fullscreen(window, fullscreen);
  const bool animated = true;
  window_stack_push(window, animated);
  
  //Put this down here so that the window is the updated window (i.e. with fullscreen)
  GRect bounds = layer_get_bounds(analog_face_layer);
  const GPoint center = grect_center_point(&bounds);
  gpath_move_to(minute_hand, center);
  gpath_move_to(hour_hand, center);

  tick_timer_service_subscribe(SECOND_UNIT, handle_second_tick);


   app_message_register_inbox_received(in_received_handler);
   app_message_register_inbox_dropped(in_dropped_handler);
   app_message_register_outbox_sent(out_sent_handler);
   app_message_register_outbox_failed(out_failed_handler);
   const uint32_t inbound_size = 1024;
   const uint32_t outbound_size = 8;
   app_message_open(inbound_size, outbound_size);

}

static void deinit(void) {
  gpath_destroy(minute_hand);
  gpath_destroy(hour_hand);

  for(int i = 0; i < NUM_CLOCK_TICKS; ++i)
    gpath_destroy(tick_paths[i]);

  tick_timer_service_unsubscribe();
  window_destroy(window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
