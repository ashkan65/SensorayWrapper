#ifndef SIMP826_H
#define SIMP826_H
/*****************************************************
A wrapper for sensoray card (826) to handle the ms updating rate!
Ver 1.0 by Ashkan Oct-2020		
In case of confusion please use: https://www.sensoray.com/downloads/man_826_hw_3.0.10.pdf#page=12&zoom=100,108,382
*****************************************************/
#include <chrono>
#include "826api.h"
#include "type.hpp"
#include <thread>  //Might be better to do the threading outside!


class Simple826{
	protected:
		/////////////////////////////////////////////
		// int GrabNextImageByTrigger(INodeMap& nodeMap, CameraPtr pCam);
		// int ResetTrigger(INodeMap& nodeMap);
		// int ConfigureTrigger(INodeMap& nodeMap);
		// Helpful macros for DIOs
		uint board;                        // change this if you want to use other than board number 0
		int errcode;  
		int boardflags;       			   // open 826 driver and find all 826 boards
		#define TSETTLE    7        	   // Settling delay after switching AIN (adjust as necessary).
		#define SLOTFLAGS  0xFFFF   	   // Timeslot flags: use all 16 timeslots. -10V to +10V 0x0000 to 0xFFFF
		int adcbuf[16]; 				   // Pointer to a buffer that will receive ADC results for the sixteen possible slots. The buffer must be large enough to
		uint slotlist = 0xFFFF; 		   //slot list for Adc_read
	public:
		Simple826();	// Currently it sets the range for all of the analog channels to -10:10V. Keep the os
		~Simple826();	//Explicitly turns all of the pins off. If there are actuators atached to the card keep them
		void SetDacOutput(uint *chan, double *volts);  //chan->channel number  volt->voltage										 ==============ANALOGOUT============
		void GetDacOutput(uint *chan, double *volts);  //chan->channel number  volt->voltage !!!! THIS IS NOT A ANALOG READ (this just returns the output current value)----
		void SetDioOutput(uint *chan, bool *val);	   //chan->channel number  val->voltage 										 ==============DIGITALOUT===========
		void ReadAdcOutput(double *data); //Read analog input adcbuf->buffer value  data->voltage received from board   ==============ANALOGREAD===========
		void ReadAdcOutput(int* adcbuf, double *data); //Read analog input adcbuf->buffer value  data->voltage received from board
		int GetError();    // Retruns error 
		void PrintError(); //Prints error
		void SetToZero(); // Setting all channels to zero
};
#endif // SIMP826_H
