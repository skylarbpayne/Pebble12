#include "Pebble12.h" //This will contain paths for the marks on the analog watch face.
#include "stdlib.h"
#include "string.h"
/*
 * Used for DrawArc (see below)
 */
static int angle_90 = TRIG_MAX_ANGLE / 4;
static int angle_180 = TRIG_MAX_ANGLE / 2;
static int angle_270 = 3 * TRIG_MAX_ANGLE / 4;

Layer* analog_face_layer;
Layer* hands_layer;

static GPath* minute_hand; //Will be used to store shape of minute hand
static GPath* hour_hand; //Same ^^ but for hour hand
static GPath* tick_paths[NUM_CLOCK_TICKS]; //stores all positions of marks on analog face

Window* window;

int16_t lim_dim;

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



/*\
|*| DrawArc function thanks to Cameron MacFarland (http://forums.getpebble.com/profile/12561/Cameron%20MacFarland)
\*/
static void graphics_draw_arc(GContext *ctx, GPoint center, int radius, int thickness, int start_angle, int end_angle, GColor c) {
	int32_t xmin = 65535000, xmax = -65535000, ymin = 65535000, ymax = -65535000;
	int32_t cosStart, sinStart, cosEnd, sinEnd;
	int32_t r, t;

	while (start_angle < 0) start_angle += TRIG_MAX_ANGLE;
	while (end_angle < 0) end_angle += TRIG_MAX_ANGLE;

	start_angle %= TRIG_MAX_ANGLE;
	end_angle %= TRIG_MAX_ANGLE;

	if (end_angle == 0) end_angle = TRIG_MAX_ANGLE;

	if (start_angle > end_angle) {
		graphics_draw_arc(ctx, center, radius, thickness, start_angle, TRIG_MAX_ANGLE, c);
		graphics_draw_arc(ctx, center, radius, thickness, 0, end_angle, c);
	} else {
		// Calculate bounding box for the arc to be drawn
		cosStart = cos_lookup(start_angle);
		sinStart = sin_lookup(start_angle);
		cosEnd = cos_lookup(end_angle);
		sinEnd = sin_lookup(end_angle);

		r = radius;
		// Point 1: radius & start_angle
		t = r * cosStart;
		if (t < xmin) xmin = t;
		if (t > xmax) xmax = t;
		t = r * sinStart;
		if (t < ymin) ymin = t;
		if (t > ymax) ymax = t;

		// Point 2: radius & end_angle
		t = r * cosEnd;
		if (t < xmin) xmin = t;
		if (t > xmax) xmax = t;
		t = r * sinEnd;
		if (t < ymin) ymin = t;
		if (t > ymax) ymax = t;

		r = radius - thickness;
		// Point 3: radius-thickness & start_angle
		t = r * cosStart;
		if (t < xmin) xmin = t;
		if (t > xmax) xmax = t;
		t = r * sinStart;
		if (t < ymin) ymin = t;
		if (t > ymax) ymax = t;

		// Point 4: radius-thickness & end_angle
		t = r * cosEnd;
		if (t < xmin) xmin = t;
		if (t > xmax) xmax = t;
		t = r * sinEnd;
		if (t < ymin) ymin = t;
		if (t > ymax) ymax = t;

		// Normalization
		xmin /= TRIG_MAX_RATIO;
		xmax /= TRIG_MAX_RATIO;
		ymin /= TRIG_MAX_RATIO;
		ymax /= TRIG_MAX_RATIO;

		// Corrections if arc crosses X or Y axis
		if ((start_angle < angle_90) && (end_angle > angle_90)) {
			ymax = radius;
		}

		if ((start_angle < angle_180) && (end_angle > angle_180)) {
			xmin = -radius;
		}

		if ((start_angle < angle_270) && (end_angle > angle_270)) {
			ymin = -radius;
		}

		// Slopes for the two sides of the arc
		float sslope = (float)cosStart/ (float)sinStart;
		float eslope = (float)cosEnd / (float)sinEnd;

		if (end_angle == TRIG_MAX_ANGLE) eslope = -1000000;

		int ir2 = (radius - thickness) * (radius - thickness);
		int or2 = radius * radius;

		graphics_context_set_stroke_color(ctx, c);

		for (int x = xmin; x <= xmax; x++) {
			for (int y = ymin; y <= ymax; y++)
			{
				int x2 = x * x;
				int y2 = y * y;

				if (
					(x2 + y2 < or2 && x2 + y2 >= ir2) && (
						(y > 0 && start_angle < angle_180 && x <= y * sslope) ||
						(y < 0 && start_angle > angle_180 && x >= y * sslope) ||
						(y < 0 && start_angle <= angle_180) ||
						(y == 0 && start_angle <= angle_180 && x < 0) ||
						(y == 0 && start_angle == 0 && x > 0)
					) && (
						(y > 0 && end_angle < angle_180 && x >= y * eslope) ||
						(y < 0 && end_angle > angle_180 && x <= y * eslope) ||
						(y > 0 && end_angle >= angle_180) ||
						(y == 0 && end_angle >= angle_180 && x < 0) ||
						(y == 0 && start_angle == 0 && x > 0)
					)
				)
				graphics_draw_pixel(ctx, GPoint(center.x+x, center.y+y));
			}
		}
	}
}

static void analog_face_update_proc(Layer* layer, GContext* ctx) {
  //Fill in the bg white
  graphics_context_set_fill_color(ctx, GColorWhite);
  graphics_fill_rect(ctx, layer_get_bounds(layer), 0, GCornerNone);

  graphics_context_set_fill_color(ctx, GColorBlack);
  for(int i = 0; i < NUM_CLOCK_TICKS; ++i)
    gpath_draw_filled(ctx, tick_paths[i]);
  GRect bounds = layer_get_bounds(layer);
  int r = (bounds.size.w < bounds.size.h ? bounds.size.w : bounds.size.h) / 2;
  graphics_draw_circle(ctx, grect_center_point(&bounds), r); //6 before
  graphics_draw_arc(ctx, grect_center_point(&bounds), lim_dim/2, 4, angle_90, angle_180, GColorBlack);
  graphics_draw_arc(ctx, grect_center_point(&bounds), lim_dim/2 - 4, 4, angle_180, angle_270, GColorBlack);

}

static void hands_update_proc(Layer* layer, GContext* ctx) {
  GRect bounds = layer_get_bounds(layer); //This will NOT be the whole clock face... Just where the analog piece lives
  const GPoint center = grect_center_point(&bounds); //Center of clock face
  lim_dim = (bounds.size.w < bounds.size.h ? bounds.size.w : bounds.size.h); //we'll use smaller dimension as radius for second hand
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
    //Update digital clock: layer_mark_dirty(digital_clock_layer);
	 //APP_LOG(APP_LOG_LEVEL_DEBUG, "Time flies WHEN YOUR HACKAFUN!");
  }
  if(units_changed & DAY_UNIT) {
    //Update date: layer_mark_dirty(date_layer);
  }
  layer_mark_dirty(analog_face_layer);
}

static void window_load(Window* window) {
  Layer* window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  analog_face_layer = layer_create(bounds); //CHANGE THIS TO LIMIT WHERE THE ANALOG CLOCK GOES!!!
  layer_set_update_proc(analog_face_layer, analog_face_update_proc);
  layer_add_child(window_layer, analog_face_layer);

  hands_layer = layer_create(layer_get_bounds(analog_face_layer));
  layer_set_update_proc(hands_layer, hands_update_proc);
  layer_add_child(analog_face_layer, hands_layer);
}

static void window_unload(Window* window) {
  layer_destroy(analog_face_layer);
  layer_destroy(hands_layer);
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
  Layer* window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
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
  // app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());
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
