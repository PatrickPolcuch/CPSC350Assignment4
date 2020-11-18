//main.cpp

#include "Queue.h"
#include "student.h"
#include <fstream>
#include <sstream>//used to get integers from a file


int main(int argc,char** argv){
  Queue <student*>*line = new Queue<student*>();
  int windowsOpen = 0;
  int currTick = 0;

  string fileName = argv[1];

  ifstream myFile;
  myFile.open(fileName);

  string curLine;
  getline(myFile,curLine);

  stringstream intWindows(curLine);//gets the string and makes it an integer
  intWindows>>windowsOpen;

  while(getline(myFile,curLine)){//puts students in queue from file
    int arrivalTime = 0;
    stringstream intAriveTime(curLine);//gets the string and makes it an integer
    intAriveTime>>arrivalTime;

    getline(myFile,curLine);
    int nextInt;
    stringstream intStudents(curLine);//gets the string and makes it an integer
    intStudents>>nextInt;

    for(int i = 0; i < nextInt;++i){
      int timeNeed = 0;
      getline(myFile,curLine);
      stringstream intTime(curLine);//gets the string and makes it an integer
      intTime>>timeNeed;
      student *stu = new student(timeNeed, arrivalTime);
      line->insert(stu);
    }
  }
  myFile.close();
  currTick = 0;

  int numStudents = line->getSize();
  int totStudentWait = 0;
  int studentWaitTen = 0;
  int longestStudentWait = 0;
  int totWindowWait = 0;
  int longestWindowWait = 0;
  int windowWaitFive = 0;

  int *windowsArr = new int[windowsOpen];
  int *windowWaitArr = new int[windowsOpen];

  for(int i = 0; i<windowsOpen; ++i){//set all to 0
    windowsArr[i] = 0;
    windowWaitArr[i] = 0;
  }

  bool isFinished = false;
  while(!line->isEmpty() || !isFinished ){
    for(int i = 0; i<windowsOpen; ++i){//decreases the amount of time left for each window by 1
      if(windowsArr[i] != 0){
        windowsArr[i] -= 1;
      }
    }
    
    while(true){//moves students to windows
      if(line->isEmpty()){
        break;
      }

      if(line->peek()->timeAr<=currTick){ //check if the next student has arrived yet
        for(int i = 0; i<windowsOpen; ++i){//check if there are any windows open
          if(windowsArr[i] == 0){
            student *nextStu = line->remove();
            windowsArr[i] = nextStu->timeNeed;
            totStudentWait += currTick-nextStu->timeAr;
            if(longestStudentWait < currTick-nextStu->timeAr){
              longestStudentWait = currTick-nextStu->timeAr;
            }
            if(currTick-nextStu->timeAr > 10){
              studentWaitTen++;
            }
            break;//student sucessfully placed at a window
          }
        }
        break;//no windows open
      }else{
        break;//no students currently in line
      }
    }

    for(int i = 0; i<windowsOpen; ++i){//Adds 1 tick to all windows without students
      if(windowsArr[i] == 0){
        windowWaitArr[i] += 1;
      }
    }

    for(int i = 0; i<windowsOpen; ++i){//determines if all the windows are finished or not
      isFinished = true;
      if(windowsArr[i] > 1){
        isFinished =false;
        break;
      }
    }

    currTick++;
  }

  for(int i = 0; i<windowsOpen; ++i){//counts the total wait time idle time for the windows, the longest window wait time, and how many were idle for 5 mins of longer
    totWindowWait += windowWaitArr[i];
    if(windowWaitArr[i] > longestWindowWait){
      longestWindowWait = windowWaitArr[i];
    }
    if(windowWaitArr[i] > 5){
      windowWaitFive++;
    }
  }



  cout<<"1. The mean student wait time : "<<totStudentWait/numStudents<<endl;
  cout<<"2. The median student wait time : "<<endl;
  cout<<"3. The longest student wait time : "<<longestStudentWait<<endl;
  cout<<"4. The number of students waiting over 10 minutes: "<<studentWaitTen<<endl;
  cout<<"5. The mean window idle time: "<<totWindowWait/windowsOpen<<endl;
  cout<<"6. The longest window idle time: "<<longestWindowWait<<endl;
  cout<<"7. Number of windows idle for over 5 minutes: "<<windowWaitFive                     <<endl;


  delete line;
  return 0;
}
