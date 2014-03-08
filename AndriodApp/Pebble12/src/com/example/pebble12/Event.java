package com.example.pebble12;

import android.util.Log;

public class Event {
	int startDay;
	int endDay;
	int startTime;
	int endTime;
	String title;
	String description;
	int hashCode;

	
	public Event(int startDay, int endDay, int startTime, int endTime, String title, String desc) {
		this.startDay = startDay;
		this.endDay = endDay;
		this.startTime = startTime;
		this.endTime = endTime;
		this.title = title;
		this.description = desc;
		String hash = startDay + endDay + startTime + endTime + title;
		this.hashCode = hash.hashCode();
	}
	
	
	//Too lazy, used an arraylist instead
	@Override
	public int hashCode() {
				return this.hashCode;
	    }
	  
	@Override
	public boolean equals(Object other){
		Event test = (Event) other;
		if(this.startDay == test.startDay &&
				this.endDay == test.endDay &&
				this.startTime == test.startTime &&
				this.endTime == test.endTime &&
				this.title.equals(test.title)) {
			return true;
		}
		else
			return false;
	}
}
