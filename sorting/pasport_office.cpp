// Assume in the Regional Passport Office, a multitude of applicants 
// arrive each day for passport renewal. A list is maintained in the 
// database to store the renewed passports arranged in the increased 
// order of passport ID. The list already would contain there cords 
// renewed till the previous day. Apply Insertion sort technique to place 
// the current day’s records in the list.
// Later the office personnel wish to sort the records based on the date 
// of renewal so as to know the count of renewals done each day. Taking 
// into consideration the fact that each record has several fields (around 
// 25 fields), follow Selection sort logic to implement the same.
// 1. Implement any one of the sorting technique
// 2. Implement the problem for both the sorting techniques 

#include <iostream>
using namespace std;

struct Date
{
    int dd;
    int mm;
    int yyyy;
};
typedef struct Date date;

struct Passport
{
    int id;
    date d;
};
typedef struct Passport passport;


bool compareDates(date d1,date d2)
{
    if (d1.yyyy < d2.yyyy)
        return true;
    else if (d1.yyyy==d2.yyyy && d1.mm<d2.mm)
        return true;
    else if (d1.yyyy==d2.yyyy && d1.mm==d2.mm && d1.dd<d2.dd)
        return true;
    else
        return false;
}

//  insertion sort of Id
void insertionSort(Passport arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Passport key = arr[i];
        int j = i - 1;
        while (key.id < arr[j].id && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// selection sort of Dates
void selectionSort(Passport arr[], int n)
{
    Passport temp;
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (compareDates(arr[j].d, arr[min].d))
                min = j;
        }
        if(min != i){
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

// Display 
void display(Passport arr[], int n)
{
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Id: ";
        cout << arr[i].id << "\t";
        cout << "Date: ";
        cout << arr[i].d.dd << "/" << arr[i].d.mm<< "/" << arr[i].d.yyyy << endl;
    }
}

int main()
{
    int i, n;
    cout << "Enter number of passport:" << endl;
    cin >> n;

    passport a[n], b[n];
    cout << "Enter Passport Details:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "Passport id: ";
        cin >> a[i].id;
        cout << "Date(dd mm yyyy): ";
        cin >> a[i].d.dd >> a[i].d.mm >> a[i].d.yyyy;
    }
    
    for (i = 0; i < n; i++)
    {
        b[i] = a[i];
    }

    cout<<"\n"<<endl;
    cout << "sorting based on Passport id:" << endl;
    insertionSort(a, n);
    display(a, n);
    
    cout<<"\n"<<endl;
    cout<<"Sorting based on date of renewal:"<< endl;
    selectionSort(b, n);
    display(b, n);
}