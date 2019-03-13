/*
	Author:	Ryan Citron (using code of what was given in class)
	Class:	c243
	File name:	main.cc
	Last updated:	3/19/2017
	Description:	This program allows a user to read from a file
					of values and inputs those values into an array
					which is dynamically created given the size of the
					array. After the values are in the arrays, it calls
					four different sorts: Bubble, Selection, Insertion,
					and Quick Sort. It also calculates the speed of
					completion of these algorithms and outputs the sorted
					arrays into files with names depending on what sort
					is being used. The user also has a chance to continue
					and see the same results, but with an already sorted
					array and 10 more randomly created integers added onto
					the already sorted array. These arrays are also
					dynamically created. Also created in this program are
					a few more functions that are helper functions to clean
					up the main. Recopy copies an array into another array.
					Random10 creates the random 10 numbers added onto the 
					end of the new arrays.
*/
					

#include <iostream>
#include <sys/time.h>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

void recopy(int original[], int copy[], int size);
                                             // Interface for recopy

bool getUserInput(ifstream &fileIn, int &size);
                                             // Interface for getUserInput

void fileOutput(int copy[], ofstream &fileOut, int size);
                                             // Interface for fileOutput
void random10(int a[], int size);

void bubbleSort(int a[], int size);          // Interface for Bubble Sort

void selectionSort(int a[], int size);       // Interface for Selection Sort

void insertionSort(int a[], int size);       // Interface for Insertion Sort

void quickSort(int a[], int left, int right);// Interface for Qucik Sort

int main(){
  
  int arraySize;                             // Size of array
  int arraySize10;                           // Size of array + 10
  int * original;                            // Pointer to original array
  int * copy;                                // Pointer to copy array
  int * original10;                          // Pointer to original + 10 array
  int * copy10;                              // Pointer to copy + 10 array
  ifstream fileIn;                           // fileIn for reading
  ofstream fileOut;                          // fileOut for writing
  struct timeval before, after;
  double timing;
  
  if(getUserInput(fileIn, arraySize) == false){ // Calls the function for user input
    cout << "Could not be opened\n";         // and checks if it worked or not
    return 0;                                // If doesn't work stop
  }
  
  original = new int[arraySize];             // Dynamically creates
                                             // an array given size
  copy = new int[arraySize];                 // Dynamically creates
                                             // the copy array
  
  for (int i = 0; (i < arraySize) &&
	 (!fileIn.eof()); i++){              	 // Using size of array
    fileIn >> original[i];                   // inputs elements from
    copy[i] = original[i];                   // file into the arrays
  }
  
  fileIn.close();                            // Closes the fileIn
 
  gettimeofday(&before, 0);                  // Time before Bubble Sort
  
  bubbleSort(copy, arraySize);               // Calls Bubble Sort

  gettimeofday(&after, 0);                   // Time after
  
  timing = (double) ((double) after.tv_sec +
		     (double) after.tv_usec/(1000*1000))-
    (double) ((double) before.tv_sec +
	      (double) before.tv_usec/(1000*1000));
                                             // Timing

  
  fileOut.open("bubblesort.dat");            // Creates file bubblesort.dat
  
  if(fileOut){      
    fileOutput(copy, fileOut, arraySize);    // Calls fileOutput
    cout << "\nThe values sorted by bubble sort have been written to the file "
	 << "bubblesort.dat\n";
  }
  else{
    cout << "\nThe values sorted by bubble sort was not written to the file "
	 << "bubblesort.dat\n";
  }

  cout << "The time it took to complete bubble sort was: " << timing << endl;

  recopy(original, copy, arraySize);         // Recopies original array to copy array

  gettimeofday(&before, 0);                  // Time before Selection Sort
  
  selectionSort(copy, arraySize);            // Calls Selection Sort

  gettimeofday(&after, 0);                   // Time after
  
  timing = (double) ((double) after.tv_sec +
		     (double) after.tv_usec/(1000*1000))-
    (double) ((double) before.tv_sec +
	      (double) before.tv_usec/(1000*1000));
                                             // Timing 
  
  fileOut.open("selectionsort.dat");         // Creates file selectionsort.dat
  
  if(fileOut){      
    fileOutput(copy, fileOut, arraySize);    // Calls fileOutput
    cout << "\nThe values sorted by selection sort have been written to the file "
	 << "selectionsort.dat\n";
  }
  else{
    cout << "\nThe values sorted by selection sort was not written to the file "
	 << "selectionsort.dat\n";
  }

  cout << "The time it took to complete selection sort was: " << timing << endl;
    
    
  recopy(original, copy, arraySize);         // Recopies original array to copy array

  gettimeofday(&before, 0);                  // Time before Insertion Sort
  
  insertionSort(copy, arraySize);            // Calls Insertion Sort

  gettimeofday(&after, 0);                   // Time after
  
  timing = (double) ((double) after.tv_sec +
		     (double) after.tv_usec/(1000*1000))-
    (double) ((double) before.tv_sec +
	      (double) before.tv_usec/(1000*1000));
                                             // Timing 
  
  fileOut.open("insertionsort.dat");         // Creates file insertionsort.dat
  
  if(fileOut){      
    fileOutput(copy, fileOut, arraySize);    // Calls fileOutput
    cout << "\nThe values sorted by insertion sort have been written to the file "
	 << "insertionsort.dat\n";
  }
  else{
    cout << "\nThe values sorted by insertion sort was not written to the file "
	 << "insertionsort.dat\n";
  }

  cout << "The time it took to complete insertion sort was: " << timing << endl;
    
    
  recopy(original, copy, arraySize);         // Recopies original array to copy array

  gettimeofday(&before, 0);                  // Time before Quick Sort
  
  quickSort(copy, 0, arraySize);             // Calls Quick Sort

  gettimeofday(&after, 0);                   // Time after
  
  timing = (double) ((double) after.tv_sec +
		     (double) after.tv_usec/(1000*1000))-
    (double) ((double) before.tv_sec +
	      (double) before.tv_usec/(1000*1000));
                                             // Timing 
  
  fileOut.open("quicksort.dat");             // Creates file quicksort.dat
  
  if(fileOut){      
    fileOutput(copy, fileOut, arraySize);    // Calls fileOutput
    cout << "\nThe values sorted by quick sort have been written to the file "
	 << "quicksort.dat\n";
  }
  else{
    cout << "\nThe values sorted by quick sort was not written to the file "
	 << "quicksort.dat\n";
  }

  cout << "The time it took to complete quick sort was: " << timing << endl;
    

  char choice = 'n';
  cout << "Would you like to quit? y/n: ";
  cin >> choice;
  if(choice == 'y') return 0;                // Give user option to quit
  cout << endl;

  arraySize10 = arraySize + 10;				 // Creates the new array size
  original10 = new int[arraySize10];         // Creates the new original array
  copy10 = new int[arraySize10];             // Creates the new copy array
  recopy(copy, original10, arraySize);       // Puts the sorted array into the new original array
  random10(original10, arraySize);           // Randomizes the last 10 integers of the array
  recopy(original10, copy10, arraySize10);   // Copies the original array into the copy array


  gettimeofday(&before, 0);                  // Time before Bubble Sort
  
  bubbleSort(copy10, arraySize10);           // Calls Bubble Sort

  gettimeofday(&after, 0);                   // Time after
  
  timing = (double) ((double) after.tv_sec +
		     (double) after.tv_usec/(1000*1000))-
    (double) ((double) before.tv_sec +
	      (double) before.tv_usec/(1000*1000));
                                             // Timing

  
  fileOut.open("bubblesort2.dat");           // Creates file bubblesort2.dat
  
  if(fileOut){      
    fileOutput(copy10, fileOut, arraySize10);// Calls fileOutput
    cout << "\nThe values sorted by bubble sort have been written to the file "
	 << "bubblesort2.dat\n";
  }
  else{
    cout << "\nThe values sorted by bubble sort was not written to the file "
	 << "bubblesort2.dat\n";
  }

  cout << "The time it took to complete bubble sort was: " << timing << endl;

  recopy(original10, copy10, arraySize);     // Recopies original10 array to copy10 array

  gettimeofday(&before, 0);                  // Time before Selection Sort
  
  selectionSort(copy10, arraySize10);        // Calls Selection Sort

  gettimeofday(&after, 0);                   // Time after
  
  timing = (double) ((double) after.tv_sec +
		     (double) after.tv_usec/(1000*1000))-
    (double) ((double) before.tv_sec +
	      (double) before.tv_usec/(1000*1000));
                                             // Timing 
  
  fileOut.open("selectionsort2.dat");        // Creates file selectionsort2.dat
  
  if(fileOut){      
    fileOutput(copy10, fileOut, arraySize10);// Calls fileOutput
    cout << "\nThe values sorted by selection sort have been written to the file "
	 << "selectionsort2.dat\n";
  }
  else{
    cout << "\nThe values sorted by selection sort was not written to the file "
	 << "selectionsort2.dat\n";
  }

  cout << "The time it took to complete selection sort was: " << timing << endl;
    
    
  recopy(original10, copy10, arraySize10);   // Recopies original10 array to copy10 array

  gettimeofday(&before, 0);                  // Time before Insertion Sort
  
  insertionSort(copy10, arraySize10);        // Calls Insertion Sort

  gettimeofday(&after, 0);                   // Time after
  
  timing = (double) ((double) after.tv_sec +
		     (double) after.tv_usec/(1000*1000))-
    (double) ((double) before.tv_sec +
	      (double) before.tv_usec/(1000*1000));
                                             // Timing 
  
  fileOut.open("insertionsort2.dat");        // Creates file insertionsort2.dat
  
  if(fileOut){      
    fileOutput(copy10, fileOut, arraySize10);// Calls fileOutput
    cout << "\nThe values sorted by insertion sort have been written to the file "
	 << "insertionsort2.dat\n";
  }
  else{
    cout << "\nThe values sorted by insertion sort was not written to the file "
	 << "insertionsort2.dat\n";
  }

  cout << "The time it took to complete insertion sort was: " << timing << endl;
    
    
  recopy(original10, copy10, arraySize10);   // Recopies original10 array to copy10 array

  gettimeofday(&before, 0);                  // Time before Quick Sort
  
  quickSort(copy10, 0, arraySize10);         // Calls Quick Sort

  gettimeofday(&after, 0);                   // Time after
  
  timing = (double) ((double) after.tv_sec +
		     (double) after.tv_usec/(1000*1000))-
    (double) ((double) before.tv_sec +
	      (double) before.tv_usec/(1000*1000));
                                             // Timing 
  
  fileOut.open("quicksort2.dat");            // Creates file quicksort2.dat
  
  if(fileOut){      
    fileOutput(copy10, fileOut, arraySize10);// Calls fileOutput
    cout << "\nThe values sorted by quick sort have been written to the file "
	 << "quicksort2.dat\n";
  }
  else{
    cout << "\nThe values sorted by quick sort was not written to the file "
	 << "quicksort2.dat\n";
  }

  cout << "The time it took to complete quick sort was: " << timing << endl;
    
    
  recopy(original10, copy10, arraySize10);   // Recopies original array to copy array
 
  return 0;

}

// This function copies the original array to the
// array that is sorted.
void recopy(int original[], int copy[], int size){
  
  for(int i = 0; i < size; i++){             // Loop to size
    copy[i] = original[i];                   // set elements equal
  }
}


// This function asks the user for the file name and
// the size of the array. It also checks if the file
// is a good input or not by checking if it is open.
// It returns true if it is successful.
bool getUserInput(ifstream &fileIn, int &size){
  string fileName;
  
  cout << "Enter the name of the file: ";    // Asks for name of file
  cin >> fileName;
  cout << "\nEnter the size of the array: "; // Asks for size of array
  cin >> size;
  
  fileIn.open(fileName.c_str());             // Opens the file given
                                             // the file name

  if(!fileIn){                               // Checks if it opened
    return false;                            // If not open return false
  }
  
  return true;                               // Successful return true
}


// This function outputs the sorted array to the specified file.
// The specified file is from the parameter fileOut that is
// passed in by reference. It also closes the file as well.
void fileOutput(int copy[], ofstream &fileOut, int size){
  
  for(int i = 0; i < size; i++){             // Loop to size
    fileOut  <<  copy[i] << endl;            // Output each element
  }                                          // to the file
  
  fileOut.close();                           // Close the file
}

void random10(int a[], int size){
  srand((time(NULL)));                       // New seed for every function call.
  for(int i = size; i < size + 10; i++){     
    a[i] = (rand()% 31999) + 1;              // Generate values to place in a[size+i]
  }
}


// Bubble Sort compares each element and sees if
// its current position is larger than the next position.
// If it is it calls the swap function and switches those
// two elements. This sorting loops until every element is
// locked in.

void bubbleSort(int a[], int size){
  int temp;
  while(0 < size - 1){                // While size > 0
    
    for(int i = 0; i < size-1; i++){  // Loops to size - 1
      
      if(a[i] > a[i+1]){              // If current is larger than next
	temp = a[i];                  	  // Swap
	a[i] = a[i+1];
	a[i+1] = temp;
      }
    }
    
    size--;                           // Decrement size since the last
                                      // element is locked in                         
  }
}
// Selection Sort takes the first element in the array and compares
// it to every element to find the smallest element in the array.
// at the end of the array it will swap the smallest element with
// the current index of the element it is comparing to.
void selectionSort(int a[], int size){
  int position;
  int temp;
  for (int i = 0; i < size - 1; i++)  // Loop until size - 1
    {
      position = i;                   // Set position of current index
      
      for (int j=i+1; j < size; j++){ // Set j to i + 1 for the next element.
	if(a[j] < a[position])        	  // Loops until j >= size
	  position = j;               	  // If j is smaller than the position
      }                               // then position = j

      if(position != i){              // If position != the original index
	temp = a[i];                  	  // swap the values
	a[i] = a[position];
	a[position] = temp;
      }
    }
}

// Insertion Sort takes the value at an index and compares
// it to "already sorted" values. When it finds a value
// smaller than itself it inserts itself in the spot before
// that value.
void insertionSort(int a[], int size){
  int temp;
  int j;

  for (int i = 1; i < size; i++){     // Loops until i == size. When it
    temp = a[i];                      // breaks out the array is fully sorted
    
    for (j = i; (j > 0) && (temp < a[j-1]); j--){ 
      a[j] = a[j-1];                  // Loop as long as j > 0 and 
                                      // a[i] < a[j-1]. Shifts the values
    }                                 // in the array up one position.
    
    a[j] = temp;	              	  // Insert a[i] into the correct spot
	   
  }
}

void quickSort(int a[], int left, int right){
  int i, j, partition, temp;
  if (right > left){
    partition = a[right]; i = left - 1; j = right-1;
                                      // Set up variables unless sorted

    for(;;){                          // Loop until conditions within loop
      
      while (a[++i] < partition);     // Continue as long as left side < partition
      while (a[--j] > partition);     // Continue as long as right side > partition
      if (i >= j) break;              // If left and right cross break the out
      
      temp = a[i];                    // Swap values of left side and right side
      a[i] = a[j];
      a[j] = temp;
    }

    temp = a[i];                      // Swap larger value of cross with partition
    a[i] = a[right];
    a[right] = temp;

    quickSort(a, left, i - 1);        // Recursive call with different right value
    quickSort(a, i + 1, right);       // Recursive call with different left value
  }
}
