#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct todolist{
    int id;
    string task;
};

int ID;

void banner();
void addTask();
void showTask();
void searchTask();
void deleteTask();
void updateTask();
int main()
{
    system("cls");
    while(true){
        banner();
        cout<<"t1.add Task"<<endl;
        cout<<"t2.show Task"<<endl;
        cout<<"t3.search Tk"<<endl;
        cout<<"t4.delete Task"<<endl;
        cout<<"t5.update Task"<<endl;

        int choice;
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case1:
                addTask();
                break;
            case2:
                showTask();
                break;
            case3:
                searchTask();
                break;
            case4:
               deleteTask();
                break;
            case5:
               // updateTask();
                break;
            default:
                break;    
        }


    }
    return 0;
}

void banner()
{
    cout<<"_______________________"<<endl;
    cout<<"My Todo"<<endl;
    cout<<"_______________________"<<endl;
}
void addTask()
{
    system("cls");
    banner();
    todolist todo;
    cout<<"Enter new task: "<<endl;
    cin.get();
    getline(cin, todo.task);
    char save;
    cout<<"save? (y/n): ";
    cin>>save;
    if(save == 'y')
    {
        ID++;
        ofstream fout;
        fout.open("todo.txt", ios::app);
        fout<<"\n" <<ID;
        fout<<"\n" <<todo.task;
        fout.close();

        char more;
        cout<<"Add more task? (y\n): ";
        cin>> more;

        if(more == 'y')
        {
            addTask();
        }
        else
        {
            system("cls");
            cout<<"Added successfully!"<<endl;
            return;
        }
    }
    system("cls");
}

void showTask(){
    system("cls");
    banner();
    todolist todo;
    ifstream fin;
    fin.open("todo.txt");
    cout<<"Task: "<<endl;

    while(!fin.eof())
    {
        fin >> todo.id;
        fin.ignore();
        getline(fin, todo.task);
        if(todo.task != ""){
            cout<<"\t"<<todo.id<<": "<<todo.task<<endl;
        }
        else{
            cout<<"\tEmpty!"<<endl;
        }
    }
    fin.close();
    char exit;
    cout<<"Exit? (y/n): ";
    cin>> exit;
    if(exit != 'y'){
        showTask();
    }
    system("cls");
}
