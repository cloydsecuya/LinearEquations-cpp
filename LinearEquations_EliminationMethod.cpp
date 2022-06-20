/*
	Linear equation using elimination method
	Date Started: December 8, 2020
	Date Finished: December 10, 2020
*/

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const int ROW=2;
const int COL=3;

//function declaration and prototype
void equation1(int list[][COL], int rsize);			//to display the value in 2D array plus linear equation


void Elimination(int list1[][COL], int rsize); 		//input the 2 values to eliminate in eqn1 and eqn2
													//then display the new equations that is already multiplied to the 2 values

void final1(int list1[][COL], int rsize,int Y);		//display the value of computed Y and the equation need to substitute the value of Y
													//process and computes the value of X
													//and finally, display the solution set of (x,y)

void final2(int list1[][COL], int rsize,int X);		//display the value of computed X and the equation need to substitute the value of X
													//process and computes the value of Y
													//and finally, display the solution set of (x,y)

int deterY(int list2[3]);							//computes the value of Y and returns the value of Y

int deterX(int list2[3]);							//computes the value of X and returns the value of X

char choice();										//display the menu and returns the value of choice


int main(){
 
    char opt;
    opt=choice();
    char decide; 

	switch(opt){
    	
       case '1':		//two dimensional
          
	do{    
		  	
				system("cls");
				std::cout<<"SYSTEMS OF LINEAR EQUATIONS:\n"
					<<"Solving by addition or elimination\n";
             
		   //ADD CODE HERE
	
		  
		   std::cout<<"This program uses Addition or Elimination Method."
			   <<endl
			   <<"We begin by setting up and evaluating the three variables x, y and the constant."
			   <<"\nFor example,\n 5x + y = -14 \nshould be entered as 5 1 -14";
		   std::cout<<"\n\nPress any key to continue....";
                       cin.ignore();
		   cin.get();

		   system("cls");	
		   
		   std::cout<<"Again, 5x + y = -14 should be entered as 5 1 -14";
		   
		   //ADD CODE HERE
		   int major_major_array[ROW][COL];			//Name too long in my case
		   
		   
		   for(int ir = 0; ir < ROW; ir++){
		   	 std::cout<<"\n \n \t Enter equation " <<ir + 1 <<": " <<endl; 
				for(int ic = 0; ic < COL; ic++){
					std::cout<<"[" <<ir <<"]" <<"[" <<ic <<"]"; 	
					cin>>major_major_array[ir][ic]; 
				}
		   }	
		   
		   std::cout<<"\n \t Input read statement...DONE! \n"
		   	   <<"\n \t Printing out a Table of 2 x 3... " <<endl; 
		   
  
			equation1(major_major_array, ROW); 		

   			Elimination(major_major_array, ROW);
   		  	

   			
			std::cout<<"\nDo you want another run? <y/n> : ";
			cin>>decide; 		
     		
			} while (decide == 'y' || decide == 'Y'); 
			
			if (decide == 'n' || decide == 'N'){
				system("cls"); 
				system("color FC");
				system("color 07"); 
				std::cout<<"\n You are about to terminate another run! "
					<<"\n \t This will close the program immediately! " <<endl; 
				
				exit(0);
			}
                     
                   
                     
       break;
       
       case '2': 
        	
        	system("cls"); 
			std::cout<<"You are about to exit the program! \n"
        		<<"Are you sure about this? \n" <<endl; 
        		
        	system("pause"); 
        	system("cls"); 
        	system("color 0c"); 
        	std::cout<<"\n \t Closing..." <<endl;
			exit(0); 
  
    } //end switch
  
        
     
    system("pause");
    return 0;
} //end main

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char choice(){		
	char decide; 
	
	do{		
		std::cout<<"<<<<<MENU>>>>>" <<endl
			<<"[1] Systems of Linear Equations " <<endl
			<<"[2] Quit" <<endl;
		
		std::cout<<"Enter your choice: ";
		cin>>decide; 		
		
			if (decide != '1' && decide != '2'){		//a prompt message if the user has input an unknown choice from the menu 
				system("color C7");
				system("color 07");
				std::cout<<"You have entered an unknown value! \n"	
					<<"\t Please try again! \n" <<endl; //Would put a cin.ignore(); cin.get(); then system("cls"); so that it looks cleaner
			}
			
	} while (decide != '1' && decide != '2'); 	
		
	return decide;
} //end choice

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void equation1(int list[][COL], int rsize){
     
	//ADD CODE HERE
	std::cout<<"\n You have entered the following values in Multi-Dimensional array! " <<endl; 
	for(int indexR = 0; indexR < rsize; indexR++){
		for(int indexC = 0; indexC < COL; indexC++)
		std::cout<<setw(6) <<list[indexR][indexC]; 
	
	std::cout<<endl; 
	}
	
	std::cout<<endl <<endl; 
	
	//Matrix Table of 2 x 3 	
	//This will help me visualize on where the index for each element is
	
	/*				
						col [0]	 col[1]	 col[2]
						-----------------------
		row [0] --	|	[0][0]	[0][1]	[0][2]	
		row [1] --	|	[1[0]	[1][1]	[1][2]
	*/
	
	std::cout<<"SOLVING SIMPLE EQUATIONS: \n" // Could be done in a for loop, but this is also good
		<<setw(6) <<list[0][0] <<"x" <<" + " <<list[0][1] <<"y" <<" = " <<list[0][2] <<endl 
		<<setw(6) <<list[1][0] <<"x" <<" + " <<list[1][1] <<"y" <<" = " <<list[1][2] <<endl
		<<"\n \n \n" <<endl;  
               
} //end equation1

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Elimination(int list1[][COL], int rsize){
	
	//ADD CODE HERE
    int elim1, elim2; // Could be in a single array with two variables named elim, but it also works
    int aX, bY, C; // Naming convention is weird in my case
    int fx, gY, Co; 
    int call_Y, call_X; 
    int array_Y[3] = { aX, bY, C }; //convert 2D to 1D; Turned up as an error for me since aX bY C is not defined yet
    int array_X[3] = { fx, gY, Co }; //convert 2D to 1D


    
	std::cout<<"___________________________________" <<endl 
		<<"Please enter a certain value that you want to eliminate! \n" <<endl 
		<<"For example if you have the following linear equations " <<endl
		<<"2x + 3y = 10 " <<endl 
		<<"4x + 5y = 15 " <<endl 
		<<"--------- \n" <<endl 
		<<"If you want to eliminate variable X...you need to input -2 " <<endl 
		<<"(for 2x to become -4x in Equation 1) and 1 (to remain the value in Equation 2) " <<endl
		<<"If you want to eliminate Y...you need to input +/- 5 in Equation 1 and +/- 3 in Equation 2 " <<endl;       
    
    std::cout<<"\n \t Enter value for Equation 1: "; 
    cin>>elim1; 
    
    std::cout<<"\n \t Enter value for Equation 2: "; 
    cin>>elim2; 
    
    std::cout<<"\n \n" <<endl;
    
    std::cout<<"ELIMINATING EQUATIONS! " <<endl 
    	<<"----------------------- \n " <<endl; 
    

	//std::cout << setw(6) << list1[0][0] *= elim1.... etc.
	std::cout<<setw(6) <<elim1 * list1[0][0] <<"x" <<" + " <<elim1 * list1[0][1] <<"y" <<" = " <<elim1 * list1[0][2] <<endl; 
	std:cout<<setw(6) <<elim2 * list1[1][0] <<"x" <<" + " <<elim2 * list1[1][1] <<"y" <<" = " <<elim2 * list1[1][2] <<endl;
		
	std::cout<<"\n========================================================================================================== \n" <<endl;  
	
	//For array_Y You could've assigned these values while you were printing the values
	aX = ( elim1 * list1[0][0] ); 
	bY = ( elim1 * list1[0][1] ); 
	C = ( elim1 * list1[0][2] ); 
	
	//For array_X Same as above; Also you're assigning the multiplier for equation one; should be elim2 * list[1][...]
	 fx = ( elim1 * list1[1][0] ); 
	 gY = ( elim1 * list1[1][1] ); 	 
	 Co = ( elim1 * list1[1][2] ); 
	 
	 //Y value passed to final1 is wrong
	 call_Y = deterY(array_Y); 
	 final1(list1, ROW, call_Y); 

	 //X value passed to final2 is wrong
	 call_X = deterX(array_X);
	 final2(list1, ROW, call_X); 	
}	
	
	
int deterY(int list2[3]){
   
    //ADD CODE HERE
	int yY; 
	
	yY = (list2[2] + (list2[0] * -1)) / list2[1];	//I don't see why you have to multiply list2[0] to -1	
	return yY;
    
} //end of deterY
 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int deterX(int list2[3]){
    
	//ADD CODE HERE
	int xX; 
	
	xX = (list2[2] + (list2[1] * -1)) / list2[0]; // Same as here

	return xX; 
    
} //end of deterX

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void final1(int list1[][COL], int rsize,int Y){			//display the value of computed Y and the equation need to substitute the value of Y
														//process and computes the value of X	
	//ADD CODE HERE 
	char again_pls; 	
	int x_comehere_pls; 
	
		list1[0][1] = list1[0][1] * Y;  
		x_comehere_pls = deterX(list1[0]); 
	
	std::cout<<"y = " <<Y <<endl
		<<"Substitute the value of Y to Equation 1: " <<endl
		<<"\t " <<list1[0][0] <<"x " <<" + " <<list1[0][1] <<"y " <<" = " <<list1[0][2] <<endl 
		<<"\n \n Then, it becomes " <<endl
		<<"\t " <<list1[0][0] <<"x " <<" + " <<list1[0][1] <<"(" <<Y <<")"  <<" = " <<list1[0][2] <<endl
		    
		<<"\n Therefore...." <<endl 
		<<"\n The solution set is: (x, y) = " <<"( " <<x_comehere_pls <<" , " <<Y <<" )" <<endl;  
	
	system("pause"); 	
	
	std::cout<<"\n \t DO YOU WANT ANOTHER RUN? "
		<<"\t <y/n> __ "; 
	cin>>again_pls; //Should be in main 
	
	if (again_pls == 'y' || again_pls == 'Y'){
		system("cls"); 
		main(); 
	}  
	
	else{
		system("cls"); 
		std::cout<<"\n \t CLOSING....."; 
		exit(0); 
	}
	
} //end of final1

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void final2(int list1[][COL], int rsize,int X){			//display the value of computed X and the equation need to substitute the value of X
														//process and computes the value of Y
	//ADD CODE HERE
    char again_pls; 
    int y_please; 
    
		list1[0][1] = list1[0][1] * X;  
		y_please = deterY(list1[0]); 
		
    std::cout<<"x = " <<X <<endl
		<<"Substitute the value of Y to Equation 1: " <<endl
		<<"\t " <<list1[0][0] <<"x " <<" + " <<list1[0][1] <<"y " <<" = " <<list1[0][2] <<endl 
		<<"\n \n Then, it becomes " <<endl
		<<"\t " <<list1[0][0] <<"x " <<" + " <<list1[0][1] <<"(" <<X <<")"  <<" = " <<list1[0][2] <<endl
		    
		<<"\n Therefore...." <<endl 
		<<"\n The solution set is: (x, y) = " <<"( " <<y_please <<" , " <<X <<" )" <<endl;  
 
 
    system("pause"); 	
	
	std::cout<<"\n \t DO YOU WANT ANOTHER RUN? "
		<<"\t <y/n> __ "; 
	cin>>again_pls; 
	
	if (again_pls == 'y' || again_pls == 'Y'){
		system("cls"); 
		main(); 
	}  
	
	else{
		system("cls"); 
		std::cout<<"\n \t CLOSING....."; 
		exit(0); 
	}
	
    
} //end of final2

