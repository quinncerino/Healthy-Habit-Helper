#include<iostream>
#include<string> 
#include <cctype>
#include<cstdlib>
#include<ctime>










using namespace std;



//select random tasks for the list
void preSelectTasks(string taskarr[], int preSelectAmount);


//add a task to the array of tasks
void addATask(string taskarr[], int usedSize, string task);


//moves a task from to do list to done list
void markAsDone(string taskarr[], int index, int & usedSize, string donearr[], int & doneUsedSize);


//function to track the value of each task and update the value
int trackValue(int & total, int valueToAdd);


//function to generate a mental health quote
void generateQuote(char quotes[]);


//check on character
void character(int tasksDone);

//Displays tasks
void displayList(string taskList[], int count);

void resources();

int optionCheck(string taskList[], int taskListCount, string doneTasks[], int doneTasksCount);

void displayMenu();




int main()
{
    string tasks[13] = {"Brush your teeth", "Wash your face", "Walk 10,000 steps", "Get 7-9 hours of sleep", "Exercise for 20 mins", 
        "Practice mindful breathing", "Take multivitamins", "Eat fruits and vegetables", "Digital detox for 3 hours", "Put on sunscreen", 
        "Brush your hair", "Take a shower", "Eat three healthy meals"};
    preSelectTasks(tasks, 3);

        
    string taskList[100];
    string doneTasks[100];
    int doneSize = 0;
    int taskListCount = 0;

    int choice = -1;
    int days = 1;
    cout << "day " << days << endl;
    
    cout << "How do you feel today? Scale 1-100: ";
    int feelings = 0; 
    cin >> feelings;

    displayMenu();
    optionCheck(taskList, taskListCount, doneTasks, doneSize);
    cout << "Stay happy!";
}
 
//aadds a user-entered task to the list of tasks
void addATask(string taskList[], int & count, string task)
{
    if (count < 100)
    {
        taskList[count] = task;
        count++;
    }
}


//displays the list of tasks
void displayList(string taskList[], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << taskList[i];
        cout << endl;
    }
}

//selects 3 random tasks and adds them to the list of tasks
void preSelectTasks(string taskarr[], string taskList[], int & count, int preSelectAmount)
{
    srand(time(0));
    int num;
    for (int i = 0; i < preSelectAmount; i++)
    {
        num = rand() % 13;
        //addATask(taskList, count, taskarr[num]);    
    }
}

//prints resources  *DONE*
void resources()
{
    cout << "Here are the resources available at ECU:\n";
    cout << "https://studenthealth.ecu.edu/ \n";
    cout << "https://counselingcenter.ecu.edu/ \n";
    cout << "https://career.ecu.edu/ \n\n"; 
}


//displays menu   *DONE*
void displayMenu()
{
    cout << "==========Healthy-Habit-Helper==========" << endl;
    cout << "1. View Tasks" << endl;
    cout << "2. Add A Task To Your List" << endl;
    cout << "3. Mark A Task As Done" << endl;
    cout << "4. Delete A Task" << endl;
    cout << "5. Display an inspirational quote" << endl;
    cout << "6. View Your Buddy" << endl;
    cout << "7. End Day" << endl;
    cout << "========================================" << endl << endl;
}

void character(int tasksDone)
{
    switch(tasksDone)
    {
        case 1:
            cout << "    |    \n\n";
            break;
        case 2:
            cout << "   \\ o /   \n";
            cout << "     |    \n";
            cout << "    / \\    \n\n";
            break;
        case 3: 
            cout << "    _O_     \n";
            cout << "   |   |   \n";
            cout << "    \\ /      \n";
            cout << "    / \\    \n\n";
            break;

        case 5:
        default:
            cout << "   ----------   \n";
            cout << "  / (*)  (*) \\      \n";
            cout << " |  _ _ _ _   |   \n";
            cout << "  \\ \\_ _ _/  /       \n";
            cout << "    --------       \n\n";
    }
}


void markAsDone(string taskarr[], int index, int & usedSize, string donearr[], int & doneUsedSize)
{
    int goal = index;
    donearr[doneUsedSize] = taskarr[index];
    doneUsedSize++;

    for (int i = usedSize - 1; i > goal; i--)
    {
        taskarr[i - 1] = taskarr[i];
    }
    usedSize--;
}

int optionCheck(string taskList[], int taskListCount, string doneTasks[], int doneTasksCount)
{
    int choice = -1; 
    
    while(choice <= 0 || choice >= 8)
    {
        cout << "Please choose one of the above options: ";
        cin >> choice;
    }

    string task;

    int index;
    
    switch(choice)
    {
        case 1: //DISPLAY THE LIST
            cout << "To-Do List:\n";
            displayList(taskList, taskListCount);
            //clear line
            displayMenu();
            optionCheck(taskList, taskListCount, doneTasks, doneTasksCount);
            
        // case 2: //ADD A TASK TO THE LIST
        //     cout << "Enter task to be added to To-Do List: ";
        //     getline(cin, task);
        //     addATask(taskList, taskListCount, task);
        //     break;

        // case 3: //MARK A TASK AS DONE
        //     cout << "Enter the number of the task you want to mark as done: ";
        //     cin >> index;
        //     markAsDone(taskarr, index - 1, taskListCount, donearr, doneUsedSize);
        //     break;

        case 4: //DELETE A TASK

            break;

        case 5: //DISPLAY AN INSPIRATIONAL QUOTE
            
            break;

        case 6: //DISPLAY CHARACTER
            //character();
            break;

        case 7:

            return 7;
    }
}