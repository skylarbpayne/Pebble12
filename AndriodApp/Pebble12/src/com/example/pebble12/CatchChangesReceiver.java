package com.example.pebble12;

import java.util.HashSet;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

/*
 * Whenever the user updates a calendar event, immediately call the notify pebble class, to update the events on the watch
 */
public class CatchChangesReceiver extends BroadcastReceiver {

    @Override
    public void onReceive(Context context, Intent intent) {
    // add processing here with some query to content provider
        // in my project I use this selection for getting events:
    	
    	Log.d("com.example.pebble","WE GOT A CALENDAR CHANGE");
    	MainActivity.notifyPebbleOfChanges();
    }
}