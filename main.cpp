#include<iostream>
#include<string>
#include <fstream>

using namespace std;

struct Data
{
	string name; //name of process
	int arrival; //arrival time
	int wait; //waiting time
	int CPU_Burst[15]; // all the cpu bursts of a process
	int r; //response
	int tar; //turnaround
	int I_O[15]; // all the IO waiting times
	int rounds; // Amout of times it has gone to CPU 
	bool inI_O; // TRUE is it is in I/O
	int queue_pos; // position in ready queue
	string status; // "OFF" means FINISHED all its cpu bursts (process completed)
	
	int queue; // Determines which time quantum to use (TQ1,TQ2, or RR) 


};

void output()
{
	ofstream cout;
	cout.open("MLFQ.txt");

}

void PrintFINAL(Data A[], int time, int cputime)
{
	float a = 0;
	double t = time;
	double cpu = cputime;
	float avg_w = 0;
	float avg_tt= 0;
	float avg_r = 0;
	
	a = 100 - ( cpu * 100 ) / t;
	
	cout<<"\n";
	cout<<"*****************************************************************************\n";
	cout<<"*****************************************************************************\n\n";
	cout<<"  ~ F I N I S H E D ~ \n\n";
	cout<<" Total time:          "<<time<<"\n";
	cout<<" CPU Utilization:     "<<a<<"%\n\n";;
	cout<<" Waiting times:      ";
	for (int i=0; i<8; i++)// WAIT
	{
		cout<<A[i].name<<"    ";
	}
	cout<<"\n                     ";
	for (int i=0; i<8; i++)
	{
		avg_w = (avg_w + A[i].wait );
		cout<<A[i].wait<<"   ";
	}
	cout<<"\n\n";
	avg_w = avg_w / 8;
	cout<<" Average Waiting Time: "<<avg_w<<"\n\n\n";

	cout<<" Turnaround times:    ";
	for (int i=0; i<8; i++) //Turn around time
	{
		cout<<A[i].name<<"     ";
	}
	cout<<"\n                     ";
	for (int i=0; i<8; i++)
	{
		avg_tt = (avg_tt + A[i].tar );
		cout<<A[i].tar<<"    ";
	}
	cout<<"\n\n";
	avg_tt = avg_tt / 8;
	cout<<" Average Turnaround Times: "<<avg_tt<<"\n\n\n";

	cout<<" Response times:    ";
	for (int i=0; i<8; i++) //Response time
	{
		cout<<A[i].name<<"     ";
	}
	cout<<"\n                     ";
	for (int i=0; i<8; i++)
	{
		avg_r = (avg_r + A[i].r );
		cout<<A[i].r<<"     ";
	}
	cout<<"\n\n";
	avg_r = avg_r / 8;
	cout<<" Average Response Times: "<<avg_r<<"\n\n";
	cout<<"*****************************************************************************\n";
	cout<<"*****************************************************************************\n";


	system ("pause");
	

}


void Print(Data A[], int pros, int time)
{
	
	int a = 1;
	cout<<"\n CPU: "<<A[pros].name<<"\n";
	cout<<" Time: "<<time<<"\n";
	cout<<" Ready QUEUE:     BURST \n";
	
	int first = A[pros].queue_pos + 1;
	
	while (a == 1 )
	{
		a = 0;
		
		for(int i = 0; i<8; i++)
		{
			if (((A[i].inI_O == false) && (A[i].name != A[pros].name)))
			{
				if ((A[i].queue_pos == first) && (A[i].status == "ON"))
				{
					cout<<"             "<<A[i].name<<"    "<<A[i].CPU_Burst[ A[i].rounds ]<<"\n";
					a = 1;
					
				}
			}
		}
		
		first = first + 1;
	}
	cout<<"\n I/O *-*-*-*-* Time: \n";
	

	for(int i = 0; i<8; i++)
	{
		if ((A[i].inI_O == true) && (A[i].status == "ON"))
		{
			cout<<" "<<A[i].name<<" ---------- "<<A[i].I_O[ A[i].rounds -1 ]<<" \n";
		}
	}
	
	cout<<"--------------------------------------\n\n";
	cout<<" Finished: ";
	for (int i = 0; i<8; i++)
	{
		if (A[i].status == "OFF")
			cout<<A[i].name<<"  ";

	}
	cout<<"\n--------------------------------------\n\n";

}
 


int main()
{
	
	Data Process[8];
	/********************************************************/
	Process[0].name = "P1";
	Process[0].arrival = 0;
	Process[0].r = -1;
	Process[0].tar = 0;
	Process[0].wait = 0;
	Process[0].queue = 1; //MLFQ Starting QUEUE

	Process[0].CPU_Burst[0] = 7;
	Process[0].I_O[0] = 24;
	Process[0].CPU_Burst[1] = 14;
	Process[0].I_O[1] = 73;
	Process[0].CPU_Burst[2] = 12;
	Process[0].I_O[2] = 31;	
	Process[0].CPU_Burst[3] = 8;
	Process[0].I_O[3] = 27;
	Process[0].CPU_Burst[4] = 9;
	Process[0].I_O[4] = 33;
	Process[0].CPU_Burst[5] = 10;
	Process[0].I_O[5] = 43;
	Process[0].CPU_Burst[6] = 12;
	Process[0].I_O[6] = 64;
	Process[0].CPU_Burst[7] = 6;
	Process[0].I_O[7] = 19;
	Process[0].CPU_Burst[8] = 9;
	Process[0].I_O[8] = 0;
	Process[0].CPU_Burst[9] = -10;

	Process[0].rounds = 0;
	Process[0].inI_O = false;
	Process[0].queue_pos = 1;
	Process[0].status = "ON";

	/**********************************************************/

	Process[1].name = "P2";
	Process[1].arrival = 0;
	Process[1].r = -1;
	Process[1].tar = 0;
	Process[1].wait = 0;
	Process[1].queue = 1;//MLFQ Starting QUEUE
	
	Process[1].CPU_Burst[0] = 8;
	Process[1].I_O[0] = 31;
	Process[1].CPU_Burst[1] = 9;
	Process[1].I_O[1] = 35;
	Process[1].CPU_Burst[2] = 10;
	Process[1].I_O[2] = 42;	
	Process[1].CPU_Burst[3] = 8;
	Process[1].I_O[3] = 43;
	Process[1].CPU_Burst[4] = 9;
	Process[1].I_O[4] = 47;
	Process[1].CPU_Burst[5] = 8;
	Process[1].I_O[5] = 43;
	Process[1].CPU_Burst[6] = 7;
	Process[1].I_O[6] = 51;
	Process[1].CPU_Burst[7] = 9;
	Process[1].I_O[7] = 32;
	Process[1].CPU_Burst[8] = 10;
	Process[1].I_O[8] = 0;
	Process[1].CPU_Burst[9] = -10;


	Process[1].rounds = 0;
	Process[1].inI_O = false;
	Process[1].queue_pos = 2;
	Process[1].status = "ON";


	/*******************************************/

	Process[2].name = "P3";
	Process[2].arrival = 0;
	Process[2].r = -1;
	Process[2].tar = 0;
	Process[2].wait = 0;
	Process[2].queue = 1;//MLFQ Starting QUEUE

	Process[2].CPU_Burst[0] = 17;
	Process[2].I_O[0] = 44;
	Process[2].CPU_Burst[1] = 19;
	Process[2].I_O[1] = 61;
	Process[2].CPU_Burst[2] = 20;
	Process[2].I_O[2] = 44;	
	Process[2].CPU_Burst[3] = 17;
	Process[2].I_O[3] = 53;
	Process[2].CPU_Burst[4] = 15;
	Process[2].I_O[4] = 77;
	Process[2].CPU_Burst[5] = 12;
	Process[2].I_O[5] = 47;
	Process[2].CPU_Burst[6] = 15;
	Process[2].I_O[6] = 71;
	Process[2].CPU_Burst[7] = 14;
	Process[2].I_O[7] = 0;
	Process[2].CPU_Burst[8] = -10;

	Process[2].rounds = 0;
	Process[2].inI_O = false;
	Process[2].queue_pos = 3;
	Process[2].status = "ON";
	/******************************************/


	Process[3].name = "P4";
	Process[3].arrival = 0;
	Process[3].r = -1;
	Process[3].tar = 0;
	Process[3].wait = 0;
	Process[3].queue = 1;//MLFQ Starting QUEUE

	Process[3].CPU_Burst[0] = 6;
	Process[3].I_O[0] = 18;
	Process[3].CPU_Burst[1] = 7;
	Process[3].I_O[1] = 21;
	Process[3].CPU_Burst[2] = 5;
	Process[3].I_O[2] = 19;	
	Process[3].CPU_Burst[3] = 4;
	Process[3].I_O[3] = 16;
	Process[3].CPU_Burst[4] = 8;
	Process[3].I_O[4] = 29;
	Process[3].CPU_Burst[5] = 7;
	Process[3].I_O[5] = 21;
	Process[3].CPU_Burst[6] = 8;
	Process[3].I_O[6] = 22;
	Process[3].CPU_Burst[7] = 6;
	Process[3].I_O[7] = 24;
	Process[3].CPU_Burst[8] = 5;
	Process[3].I_O[8] = 0;
	Process[3].CPU_Burst[9] = -10;

	Process[3].rounds = 0;
	Process[3].inI_O = false;
	Process[3].queue_pos = 4;
	Process[3].status = "ON";

	/******************************************/


	Process[4].name = "P5";
	Process[4].arrival = 0;
	Process[4].r = -1;
	Process[4].tar = 0;
	Process[4].wait = 0;
	Process[4].queue = 1;//MLFQ Starting QUEUE

	Process[4].CPU_Burst[0] = 5;
	Process[4].I_O[0] = 81;
	Process[4].CPU_Burst[1] = 4;
	Process[4].I_O[1] = 82;
	Process[4].CPU_Burst[2] = 5;
	Process[4].I_O[2] = 71;	
	Process[4].CPU_Burst[3] = 3;
	Process[4].I_O[3] = 61;
	Process[4].CPU_Burst[4] = 5;
	Process[4].I_O[4] = 62;
	Process[4].CPU_Burst[5] = 4;
	Process[4].I_O[5] = 51;
	Process[4].CPU_Burst[6] = 3;
	Process[4].I_O[6] = 77;
	Process[4].CPU_Burst[7] = 4;
	Process[4].I_O[7] = 61;
    Process[4].CPU_Burst[8] = 3;
	Process[4].I_O[8] = 42;
	Process[4].CPU_Burst[9] = 5;
	Process[4].I_O[9] = 0;
	Process[4].CPU_Burst[10] = -10;

	Process[4].rounds = 0;
	Process[4].inI_O = false;
	Process[4].queue_pos = 5;
	Process[4].status = "ON";

	/***************************************************/

	Process[5].name = "P6";
	Process[5].arrival = 0;
	Process[5].r = -1;
	Process[5].tar = 0;
	Process[5].wait = 0;
	Process[5].queue = 1;//MLFQ Starting QUEUE

	Process[5].CPU_Burst[0] = 21;
	Process[5].I_O[0] = 35;
	Process[5].CPU_Burst[1] = 22;
	Process[5].I_O[1] = 43;
	Process[5].CPU_Burst[2] = 26;
	Process[5].I_O[2] = 29;	
	Process[5].CPU_Burst[3] = 21;
	Process[5].I_O[3] = 34;
	Process[5].CPU_Burst[4] = 25;
	Process[5].I_O[4] = 43;
	Process[5].CPU_Burst[5] = 23;
	Process[5].I_O[5] = 29;
	Process[5].CPU_Burst[6] = 21;
	Process[5].I_O[6] = 0;
	Process[5].CPU_Burst[7] = -10;

	Process[5].rounds = 0;
	Process[5].inI_O = false;
	Process[5].queue_pos = 6;
	Process[5].status = "ON";

	/**************************************/

	Process[6].name = "P7";
	Process[6].arrival = 0;
	Process[6].r = -1;
	Process[6].tar = 0;
	Process[6].wait = 0;
	Process[6].queue = 1;//MLFQ Starting QUEUE
	
	Process[6].CPU_Burst[0] = 24;
	Process[6].I_O[0] = 55;
	Process[6].CPU_Burst[1] = 23;
	Process[6].I_O[1] = 52;
	Process[6].CPU_Burst[2] = 24;
	Process[6].I_O[2] = 61;	
	Process[6].CPU_Burst[3] = 22;
	Process[6].I_O[3] = 31;
	Process[6].CPU_Burst[4] = 22;
	Process[6].I_O[4] = 43;
	Process[6].CPU_Burst[5] = 20;
	Process[6].I_O[5] = 0;
	Process[6].CPU_Burst[6] = -10;

	Process[6].rounds = 0;
	Process[6].inI_O = false;
	Process[6].queue_pos = 7;
	Process[6].status = "ON";

	/*****************************************/

	Process[7].name = "P8";
	Process[7].arrival = 0;
	Process[7].r = -1;
	Process[7].tar = 0;
	Process[7].wait = 0;
	Process[7].queue = 1;//MLFQ Starting QUEUE

	Process[7].CPU_Burst[0] = 12;
	Process[7].I_O[0] = 52;
	Process[7].CPU_Burst[1] = 14;
	Process[7].I_O[1] = 42;
	Process[7].CPU_Burst[2] = 15;
	Process[7].I_O[2] = 31;	
	Process[7].CPU_Burst[3] = 17;
	Process[7].I_O[3] = 21;
	Process[7].CPU_Burst[4] = 16;
	Process[7].I_O[4] = 43;
	Process[7].CPU_Burst[5] = 12;
	Process[7].I_O[5] = 31;
	Process[7].CPU_Burst[6] = 13;
	Process[7].I_O[6] = 32;
	Process[7].CPU_Burst[7] = 15;
	Process[7].I_O[7] = 0;
	Process[7].CPU_Burst[8] = -10;

	Process[7].rounds = 0;
	Process[7].inI_O = false;
	Process[7].queue_pos = 8;
	Process[7].status = "ON";

	/****************************************************************/
	/****************************************************************/

	int repeat = 0; // hits '1' when all process are over
	int cycle = 0; // hits '1' when ALL processes have gone at least once
	int time = 0; // time unit
	int pros = 0;	//Determines which process enters CPU
	int avg_r = 0; // Average Response time
	int follow = 0; // IMPORTANT Variable that saves the process that will enter CPU NEXT.
	int round_before = 0; // saves the value of the previous round of a process ( 1 round = 1 cpu burst complete )
	bool queue_empty = false;
	int found = 0;
	int tempqueue = 0; // used when queue is empty, takes the queue pos of the one in the cpu.
	int CPU_UTI = 0; // counts cpu free time.
	int last_process = 0; // USED WHEN TEHRE IS ONLY ONE PROCESS LEFT (to save which proces it is)
	int last_contact = 0; // USED WHEN THERE IS ONLY ONE PROCESS LEFT (to contact switch)
	int first_process = 0; // to determine the the RESPONSE OF THE FIRST PROCESSS ONLY
	int RR7 =7 ; // TIME QUANTUM FOR QUEUE 1
	int RR12 = 12;// TIME QUANTUM FOR QUEUE 2
	int kick = -1; // if a process will be kicked, then the value of the variable will be the one OF THE NEW process.

	while (repeat == 0) //-------------------------------------------------------------------------------------------------------------------------WHILE
	{	
	
		if (time == 0)
		{
			Print(Process,pros,time);
			Process[pros].r = 0;
		}
		
		found = 0;
		time++;
		
		if (cycle == 0)
		{	
			//cout<<"cycle";

			if ((pros != follow) || (last_contact == 1)) // CHECK IF NEXT PROCESS COMES
			{
				cout<<"-------------------------------CONTACT SWITCH";
				last_contact = 0;
				pros = follow;
				Print(Process,pros,(time-1));
				Process[pros].arrival = 0;
			}

			
			if (Process[pros].queue == 1)//----------------------------------------------------------------------------------------------RR-TQ5
			{
				for (int i = 0; i<8; i++) // ADDS WAITING TIME TO ALL NON-CPU Processes 
				{
					if ((Process[i].name != Process[pros].name) && (Process[i].inI_O == false) && (Process[i].status == "ON"))
					{
						Process[i].wait = Process[i].wait + 1;
					}
				
				}

				if (Process[pros].status == "ON") // Substracts 1 from the process on the CPU.
				{
					Process[pros].CPU_Burst[ Process[pros].rounds ] = Process[pros].CPU_Burst[ Process[pros].rounds ] - 1;
					//cout<<" "<<Process[pros].CPU_Burst[ Process[pros].rounds ];
					RR7--;
				}

				if (Process[pros].r == -1) // CALCULATING response time of Current Process
				{
					/*if (first_process == 0)
					{
						Process[pros].r = 0;
						first_process = 1;
					}*/
					Process[pros].r = time-1;
				}

				for (int i = 0; i<8; i++) // SUBSTRACTS I/O TIMES
				{
					if ((Process[i].inI_O == true) && (Process[i].status == "ON") && (Process[i].I_O[ Process[i].rounds -1 ] >0))
						Process[i].I_O[ Process[i].rounds -1 ] = Process[i].I_O[ Process[i].rounds -1 ] - 1;
				}


				for (int i = 0; i<8; i++)// TAKES PROCESES OF I/O
				{
					int last = 0;
				
					if ((Process[i].inI_O == true) && (Process[i].I_O[ Process[i].rounds -1 ] == 0) && (Process[i].status == "ON")) 
					{
						//cout<<"--1 OUT IO--";
						Process[i].inI_O = false;

						for (int i = 0; i<8; i++)
						{
							if ((Process[i].queue_pos > last ) && (Process[i].inI_O == false) && (Process[i].status == "ON"))
								last = Process[i].queue_pos;
						}
					
						Process[i].queue_pos = last + 1;
					
					}
				}


				if ((RR7 == 0) && (Process[pros].CPU_Burst[ Process[pros].rounds ] > 0) && (Process[pros].status == "ON")) // checks if process will be demoted
				{
					RR7=7;
					Process[pros].queue = 2; // Demoted to QUEUE 2
					Process[pros].arrival = time;

					repeat = 1; // search if there is still OTHER process in the queue or IO
					for (int i = 0; i<8; i++)
					{
						if ((Process[i].name != Process[pros].name) && (Process[i].status == "ON"))
						{
							repeat = 0;
						}
					}

					if ( repeat != 1 )
					{
						int prevfollow = follow;
						int next = 1000000;
					
						for (int i=0; i<8; i++) //LOOKS FOR QUEUE 1 PRIORITY 
						{
							if ((Process[i].inI_O == false ) && (Process[i].arrival < next) && (Process[i].queue == 1) && (Process[i].status == "ON"))
							{
								next = Process[i].arrival;
								follow = i;
							}
						}

						if (follow == prevfollow)// IF DID NOT FIND ANY Queue 1 priority
						{
							for (int i=0; i<8; i++)
							{
								if ((Process[i].inI_O == false ) && (Process[i].arrival < next) && (Process[i].queue == 2) && (Process[i].status == "ON"))
								{
									next = Process[i].arrival;
									follow = i;
								}
							}
						}

						if (follow == prevfollow)// IF DID NOT FIND ANY Queue 2 priority
						{
							for (int i=0; i<8; i++)
							{
								if ((Process[i].inI_O == false ) && (Process[i].arrival < next) && (Process[i].queue == 3) && (Process[i].status == "ON"))
								{
									next = Process[i].arrival;
									follow = i;
								}
							}
						}

						if (follow == prevfollow) // NO OTHER PROCESS IS AVAILABLE
						{
							//cout<<"--ENTERED--";
							tempqueue = Process[pros].queue_pos + 1;
						}
					}
					
				}

				if (Process[pros].CPU_Burst[ Process[pros].rounds ] == 0) /*&& (Process[pros].I_O[Process[pros].rounds] != 0) && (Process[pros].status == "ON")*/// CHECK IF PROCESS ENDED, choose next in queue
				{
					RR7=7;
					last_process = pros; // Saves the last process that went on the CPU.
					round_before = Process[pros].rounds;
					Process[pros].rounds = Process[pros].rounds + 1;
				
					if (Process[pros].CPU_Burst[ Process[pros].rounds ] == -10)
					{
						Process[pros].tar = time;
						Process[pros].status = "OFF";
					}

					if (Process[pros].status == "ON")
					{	
						Process[pros].arrival = time + Process[pros].I_O[ Process[pros].rounds - 1 ];
						Process[pros].inI_O = true;
					}

					repeat = 1; // search if there is still OTHER process in the queue or IO
					for (int i = 0; i<8; i++)
					{
						if ((Process[i].name != Process[pros].name) && (Process[i].status == "ON"))
						{
							repeat = 0;
						}
					}

					if ( repeat != 1 ) // LOOKSC FOR NEXT PROCESS
					{
						int prevfollow = follow;
						int next = 1000000;
					
						for (int i=0; i<8; i++) //LOOKS FOR QUEUE 1 PRIORITY 
						{
							if ((Process[i].inI_O == false ) && (Process[i].arrival < next) && (Process[i].queue == 1) && (Process[i].status == "ON"))
							{
								next = Process[i].arrival;
								follow = i;
							}
						}

						if (follow == prevfollow)// IF DID NOT FIND ANY Queue 1 priority
						{
							for (int i=0; i<8; i++)
							{
								if ((Process[i].inI_O == false ) && (Process[i].arrival < next) && (Process[i].queue == 2) && (Process[i].status == "ON"))
								{
									next = Process[i].arrival;
									follow = i;
								}
							}
						}

						if (follow == prevfollow)// IF DID NOT FIND ANY Queue 2 priority
						{
							for (int i=0; i<8; i++)
							{
								if ((Process[i].inI_O == false ) && (Process[i].arrival < next) && (Process[i].queue == 3) && (Process[i].status == "ON"))
								{
									next = Process[i].arrival;
									follow = i;
								}
							}
						}

						if (follow == prevfollow) // NO OTHER PROCESS IS AVAILABLE
						{
							//cout<<"--ENTERED--";
							tempqueue = Process[pros].queue_pos + 1;
						}
					}
			
				}
			
			
			}//-----------------------------------------------------------------------------------------------------------------------------END-RR-TQ5
			else
			{

			







			if (Process[pros].queue == 2)//-----------------------------------------------------------------------------------------------RR-TQ10
			{
				for (int i = 0; i<8; i++) // ADDS WAITING TIME TO ALL NON-CPU Processes 
				{
					if ((Process[i].name != Process[pros].name) && (Process[i].inI_O == false) && (Process[i].status == "ON"))
					{
						Process[i].wait = Process[i].wait + 1;
					}
				
				}

				if (Process[pros].status == "ON") // Substracts 1 from the process on the CPU.
				{
					Process[pros].CPU_Burst[ Process[pros].rounds ] = Process[pros].CPU_Burst[ Process[pros].rounds ] - 1;
					//cout<<" "<<Process[pros].CPU_Burst[ Process[pros].rounds ];
					RR12--;
				}

				if (Process[pros].r == -1) // CALCULATING response time of Current Process
				{
					/*if (first_process == 0)
					{
						Process[pros].r = 0;
						first_process = 1;
					}*/
				Process[pros].r = time-1;
				}

				for (int i = 0; i<8; i++) // SUBSTRACTS I/O TIMES
				{
					if ((Process[i].inI_O == true) && (Process[i].status == "ON") && (Process[i].I_O[ Process[i].rounds -1 ] >0))
						Process[i].I_O[ Process[i].rounds -1 ] = Process[i].I_O[ Process[i].rounds -1 ] - 1;
				}


				for (int i = 0; i<8; i++)// TAKES PROCESES OF I/O
				{
					int last = 0;
				
					if ((Process[i].inI_O == true) && (Process[i].I_O[ Process[i].rounds -1 ] == 0) && (Process[i].status == "ON")) 
					{
						//cout<<"--1 OUT IO--";
						Process[i].inI_O = false;

						for (int i = 0; i<8; i++)
						{
							if ((Process[i].queue_pos > last ) && (Process[i].inI_O == false) && (Process[i].status == "ON"))
								last = Process[i].queue_pos;
						}
					
						Process[i].queue_pos = last + 1;
					}
				}

				kick = -1;
				if (Process[pros].CPU_Burst[ Process[pros].rounds ] != 0)
				{
					for (int i=0;i<8;i++) //Search for kick
					{
						if ((Process[i].queue == 1) && (Process[i].inI_O == false) && (Process[i].status == "ON"))
						{
							kick = i;
							break;
						}
					}

				}
				
				if ((kick != -1) && (Process[pros].CPU_Burst[ Process[pros].rounds ] != 0)) // changing next process
				{
					RR12=12;
					Process[pros].arrival = time;
					follow = kick;
				}
				
				
				if ((RR12 == 0) && (Process[pros].CPU_Burst[ Process[pros].rounds ] > 0) && (Process[pros].status == "ON") && (kick == -1)) // checks if process will be demoted
				{
					RR12=12;
					Process[pros].queue = 3; // Demoted to QUEUE 3
					Process[pros].arrival = time;

					repeat = 1; // search if there is still OTHER process in the queue or IO
					for (int i = 0; i<8; i++)
					{
						if ((Process[i].name != Process[pros].name) && (Process[i].status == "ON"))
						{
							repeat = 0;
						}
					}

					if ( repeat != 1 )
					{
						int prevfollow = follow;
						int next = 1000000;
					
						for (int i=0; i<8; i++) //LOOKS FOR QUEUE 1 PRIORITY 
						{
							if ((Process[i].inI_O == false ) && (Process[i].arrival < next) && (Process[i].queue == 1) && (Process[i].status == "ON"))
							{
								next = Process[i].arrival;
								follow = i;
							}
						}

						if (follow == prevfollow)// IF DID NOT FIND ANY Queue 1 priority
						{
							for (int i=0; i<8; i++)
							{
								if ((Process[i].inI_O == false ) && (Process[i].arrival < next) && (Process[i].queue == 2) && (Process[i].status == "ON"))
								{
									next = Process[i].arrival;
									follow = i;
								}
							}
						}

						if (follow == prevfollow)// IF DID NOT FIND ANY Queue 2 priority
						{
							for (int i=0; i<8; i++)
							{
								if ((Process[i].inI_O == false ) && (Process[i].arrival < next) && (Process[i].queue == 3) && (Process[i].status == "ON"))
								{
									next = Process[i].arrival;
									follow = i;
								}
							}
						}

						if (follow == prevfollow) // NO OTHER PROCESS IS AVAILABLE
						{
							//cout<<"--ENTERED--";
							tempqueue = Process[pros].queue_pos + 1;
						}
					}
					
				}

				if (Process[pros].CPU_Burst[ Process[pros].rounds ] == 0)/*&& (Process[pros].I_O[Process[pros].rounds] != 0) && (Process[pros].status == "ON")*/// CHECK IF PROCESS ENDED, choose next in queue
				{
					RR12=12;
					last_process = pros; // Saves the last process that went on the CPU.
					round_before = Process[pros].rounds;
					Process[pros].rounds = Process[pros].rounds + 1;
				
					if (Process[pros].CPU_Burst[ Process[pros].rounds ] == -10)
					{
						Process[pros].tar = time;
						Process[pros].status = "OFF";
					}

					if (Process[pros].status == "ON")
					{	
						Process[pros].arrival = time + Process[pros].I_O[ Process[pros].rounds - 1 ];
						Process[pros].inI_O = true;
					}

					repeat = 1; // search if there is still OTHER process in the queue or IO
					for (int i = 0; i<8; i++)
					{
						if ((Process[i].name != Process[pros].name) && (Process[i].status == "ON"))
						{
							repeat = 0;
						}
					}

					if ( repeat != 1 ) // LOOKS FOR NEXT PROCESS
					{
						int prevfollow = follow;
						int next = 1000000;
					
						for (int i=0; i<8; i++) //LOOKS FOR QUEUE 1 PRIORITY 
						{
							if ((Process[i].inI_O == false ) && (Process[i].arrival < next) && (Process[i].queue == 1) && (Process[i].status == "ON"))
							{
								next = Process[i].arrival;
								follow = i;
							}
						}

						if (follow == prevfollow)// IF DID NOT FIND ANY Queue 1 priority
						{
							for (int i=0; i<8; i++)
							{
								if ((Process[i].inI_O == false ) && (Process[i].arrival < next) && (Process[i].queue == 2) && (Process[i].status == "ON"))
								{
									next = Process[i].arrival;
									follow = i;
								}
							}
						}

						if (follow == prevfollow)// IF DID NOT FIND ANY Queue 2 priority
						{
							for (int i=0; i<8; i++)
							{
								if ((Process[i].inI_O == false ) && (Process[i].arrival < next) && (Process[i].queue == 3) && (Process[i].status == "ON"))
								{
									next = Process[i].arrival;
									follow = i;
								}
							}
						}

						if (follow == prevfollow) // NO OTHER PROCESS IS AVAILABLE
						{
							//cout<<"--ENTERED--";
							tempqueue = Process[pros].queue_pos + 1;
						}
					}
			
				}



			}//--------------------------------------------------------------------------------------------------------------------------END-RR-TQ10
			else 
			{






			if (Process[pros].queue == 3)//----------------------------------------------------------------------------------------------FCFS
			{	

				for (int i = 0; i<8; i++) // ADDS WAITING TIME TO ALL NON-CPU Processes 
				{
					if ((Process[i].name != Process[pros].name) && (Process[i].inI_O == false) && (Process[i].status == "ON"))
					{
						Process[i].wait = Process[i].wait + 1;
					}
				
				}

				if (Process[pros].status == "ON") // Substracts 1 from the processes CPU.
				{
					Process[pros].CPU_Burst[ Process[pros].rounds ] = Process[pros].CPU_Burst[ Process[pros].rounds ] - 1;
					//cout<<" "<<Process[pros].CPU_Burst[ Process[pros].rounds ];
				}

				if (Process[pros].r == -1) // CALCULATING response time of Current Process
				{
					/*if (first_process == 0)
					{
						Process[pros].r = 0;
						first_process = 1;
					}*/
					Process[pros].r = time-1;
				}

				for (int i = 0; i<8; i++) // SUBSTRACTS I/O TIMES
				{	
					if ((Process[i].inI_O == true) && (Process[i].status == "ON") && (Process[i].I_O[ Process[i].rounds -1 ] >0))
						Process[i].I_O[ Process[i].rounds -1 ] = Process[i].I_O[ Process[i].rounds -1 ] - 1;
				}

				for (int i = 0; i<8; i++)// TAKES PROCESES OF I/O
				{
					int last = 0;
				
					if ((Process[i].inI_O == true) && (Process[i].I_O[ Process[i].rounds -1 ] == 0) && (Process[i].status == "ON")) 
					{
						//cout<<"--1 OUT IO--";
						Process[i].inI_O = false;

						/*if (Process[i].CPU_Burst[ Process[i].rounds + 1 ] == -10 )
						{
							Process[i].queue_pos = -1;
							Process[i].status = "OFF";
						} 
						else*/
						{
							for (int i = 0; i<8; i++)
							{
								if ((Process[i].queue_pos > last ) && (Process[i].inI_O == false) && (Process[i].status == "ON"))
									last = Process[i].queue_pos;
							}
					
							Process[i].queue_pos = last + 1;
					
						}	
					}
				}
			
				kick = -1;
				if (Process[pros].CPU_Burst[ Process[pros].rounds ] != 0)
				{
					for (int i=0;i<8;i++) //Search for kick
					{
						if ((Process[i].queue == 1) && (Process[i].inI_O == false) && (Process[i].status == "ON"))
						{
							kick = i;
							break;
						}
					}

				}
				
				if ((kick != -1) && (Process[pros].CPU_Burst[ Process[pros].rounds ] != 0)) // changing next process
				{
					Process[pros].arrival = time;
					follow = kick;
				}
				
				if (Process[pros].CPU_Burst[ Process[pros].rounds ] == 0) /*&& (Process[pros].I_O[Process[pros].rounds] != 0) && (Process[pros].status == "ON")*/// CHECK IF PROCESS ENDED, choose next in queue
				{
					last_process = pros; // Saves the last process that went on the CPU.
					round_before = Process[pros].rounds;
					Process[pros].rounds = Process[pros].rounds + 1;
				
					if (Process[pros].CPU_Burst[ Process[pros].rounds ] == -10)
					{
						Process[pros].tar = time;
						Process[pros].status = "OFF";
					}

					if (Process[pros].status == "ON")
					{	
						Process[pros].arrival = time + Process[pros].I_O[ Process[pros].rounds - 1 ];
						Process[pros].inI_O = true;
					}

					repeat = 1;
					for (int i = 0; i<8; i++)
					{
						if ((Process[i].name != Process[pros].name) && (Process[i].status == "ON"))
						{
							repeat = 0;
						}
					}

					if ( repeat != 1 )
					{
						int prevfollow = follow;
						int next = 1000000;

						for (int i=0; i<8; i++)
						{
							//if ( (Process[i].queue_pos == next) && (Process[i].status == "ON"))
								//follow = i;
							if ((Process[i].inI_O == false ) && (Process[i].arrival < next) && (Process[i].status == "ON"))
							{
								next = Process[i].arrival;
								follow = i;
							}

						}

						if (follow == prevfollow)
						{
							//cout<<"--ENTERED--";
							tempqueue = Process[pros].queue_pos + 1;
						}
					}
			
				}

			}//------------------------------------------------------------------------------------------------------------END OF FCFS

		}//ENDS RR12 ELSE
		}//ENDS RR7 ELSE
		

		}//-------------------------------------------------------------------------------------------------------------------END OF CYCLE == 0
		else 
		if (cycle == 1)//-----------------------------------------------------------------------------------------------------NO PROCESS IN QUEUE
		{
			CPU_UTI++;

			for (int i = 0; i<8; i++) // ADDS WAITING TIME TO ALL NON-CPU Processes 
			{
				if ((Process[i].inI_O == false) && (Process[i].status == "ON"))
				{
					Process[i].wait = Process[i].wait + 1;
				}
				
			}

			for (int i = 0; i<8; i++) // SUBSTRACTS I/O TIMES
			{
				if ((Process[i].inI_O == true) && (Process[i].status == "ON") && (Process[i].I_O[ Process[i].rounds -1 ] >0))
				{
					Process[i].I_O[ Process[i].rounds -1 ] = Process[i].I_O[ Process[i].rounds -1 ] - 1;
					//cout<<Process[i].I_O[ Process[i].rounds -1 ]<<" "<<time<< " - ";
				}
			}

			for (int i = 0; i<8; i++)// TAKES PROCESES OF I/O, when queue empty
			{	
				if ((Process[i].inI_O == true) && (Process[i].I_O[ Process[i].rounds -1 ] == 0) && (Process[i].status == "ON")) 
				{
					Process[i].inI_O = false;
					Process[i].queue_pos = tempqueue;
					follow = i;
				}
			}


		}//-----------------------------------------------------------------------------------------------------------END OF "NO PROCESS IN QUEUE"

		cycle = 1;
		for (int i=0; i<8; i++)
		{
			if ((Process[i].inI_O == false) && (Process[i].status == "ON")) 
			{
				cycle = 0;
			}

		}
	
		if (repeat == 1)
		{
			for (int i = 0; i<8; i++)
			{
				if (Process[i].status == "ON")
				{
					repeat = 0;
					last_contact = 1;
				}
			}

		}
	
	
	
}//--------------------------------------------------------------------------------------------------------------------------------------------END WHILE

	PrintFINAL(Process,time,CPU_UTI);
	
	return 0;
}