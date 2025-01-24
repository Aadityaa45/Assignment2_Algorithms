#include <iostream>
#include <vector>
#include <string>
using namespace std;

//this is the function for doing linear search operation to find the students whose age are greater then 5 feet
//this function primarily require only height vector or array but other vectors of studen infromation is also taken as argument here
void LinearSearch(vector<string> name, vector<float> height, vector<string> course, vector<int> year, int required_height) {
    int iterate_count = 0; //this is the variable initalisation and declaration of iteration count for further analysis 
    int comparision_count=0;
    cout << "\nSTUDENTS SELECTED (HEIGHT ABOVE OR EQUAL TO 5 FEET):" << endl;
    cout << "-------------------------------------------------" << endl;
    //this is the main part of linear search in which we iterate over the given data structure and find the things we want
    for (int i = 0; i < height.size(); i++) {
        if (height[i] >= required_height) { 
            cout << "NAME: " << name[i] << " || HEIGHT: " << height[i] << " || COURSE: " << course[i] << " || YEAR: " << year[i] << endl;
            comparision_count++; //increasing the comparision count 
        }
        iterate_count++; //increasing the iterate count
    }
    cout << "TOTAL ITERATIONS: " << iterate_count << endl;  
    cout<<"TOTAL COMPARISIONS MADE:"<<comparision_count;
}


//here the bubble sort is used to sort the given array to allow for binary search
void sort(vector<string> &name, vector<float> &height, vector<string> &course, vector<int> &year){
    
    for(int i=0;i<height.size()-1;i++){
        bool flag = false;
        for(int j=0;j<height.size()-1-i;j++){
            if(height[j]>height[j+1]){
                float temp1 = height[j];
                height[j]=height[j+1];
                height[j+1]=temp1;
    /*with the height values we also swapped the other information that they act as same for a same person with theri indexes*/
                string temp2 = name[j];
                name[j]=name[j+1];
                name[j+1]=temp2;

                int temp3 = year[j];
                year[j]=year[j+1];
                year[j+1]=temp3;

                string temp4 = course[j];
                course[j]=course[j+1];
                course[j+1]=temp4;
                flag=true;
            }
            if(flag==false){
                break;
            }
        }
    }
}

//this is the function whih implements the binary search 
//it also takes the same parameteres as Linear search
void BinarySearch(vector<string> name, vector<float> height, vector<string> course, vector<int> year, int height_required){
    int iterate_count = 0;  //similarly here also declaring iteration counts and comparision counts 
    int comaprision_count = 0;
    int l=0;  //initialising and declaring left i.e. l variable
    int r=height.size()-1; //initialising and declsring r variable
    int height_key=height_required;
    int index_value=-1; //declaring index value to hold the index value of the firs occurance
    while(l<=r){
        int mid = (r+l)/2;
        comaprision_count++;  //incrementing the comparision count as here aslo the comparisions are made to find the mid value
        if(height[mid]==height_key){
            index_value=mid;
            r=mid-1;  //the right side is changed in order to find the first occurance
            
        }
        else if(height_key>height[mid]){
            l=mid+1;
        }
        else if(height_key<height[mid]){
            r=mid-1;
        }
    }
    if (index_value == -1) {
        index_value = l;
    }
    //now as array is sorted in binary search so we find the very first occurance and from there we can simply iterate to the end of the array as it containing the heights greater then 5
    for(int i=index_value;i<height.size();i++){
        cout << "\nNAME: " << name[i] << " || HEIGHT: " << height[i]<< " || COURSE: " << course[i] << " || YEAR: " << year[i] << endl;
        iterate_count++;
        comaprision_count++;
    }
    cout<<"TOTAL ITERATES:"<<iterate_count<<endl;
    cout<<"COMPARISION COUNT:"<<comaprision_count;
}
int main() {
    //initialising four vectors seperately to store the student details
    //here sepeate vectors are used because if linked list is used then it will conatin more memory and operations like binary seacrh is not vailable in linked list
    vector<string> student;
    vector<float> height;
    vector<string> course;
    vector<int> year;

    cout << "STUDENT REGISTRATION FORM FOR DRAMA EVENT" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\nENTER THE DETAILS ASKED IN THE FORM OR TYPE 'NO' TO STOP THE REGISTRATION PROCESS" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;


    //here there is no limit of students maximum students can register thats why while loop is used
    while (true) {
        cout << "\nENTER THE STUDENT NAME: ";
        string name_holder;
        getline(cin, name_holder); 
        
        if (name_holder == "NO" || name_holder == "no" || name_holder == "No") {
            cout << "\nREGISTRATIONS CLOSED!" << endl;
            cout << "-------------------------------------------------" << endl;
            break;
        }
        student.push_back(name_holder);

        float height_holder;
        cout << "\nENTER THE STUDENT HEIGHT IN FT.: ";
        cin >> height_holder;
        height.push_back(height_holder);

        // Ignore leftover newline in buffer
        cin.ignore();


        string course_holder;
        cout << "\nENTER THE COURSE STUDENT IS STUDYING IN: ";
        getline(cin, course_holder);
        course.push_back(course_holder);


        int year_holder;
        cout << "\nENTER THE YEAR OF STUDY: ";
        cin >> year_holder;
        year.push_back(year_holder);

        cin.ignore();

        cout << "-------------------------------------------------" << endl;
    }

    cout << "\nSTUDENTS REGISTERED FOR THE DRAMA EVENT:" << endl;
    cout << "-------------------------------------------------" << endl;
    for (int i = 0; i < student.size(); i++) {
        cout << "\nNAME: " << student[i] << " || HEIGHT: " << height[i]<< " || COURSE: " << course[i] << " || YEAR: " << year[i] << endl;
    }
    cout << "-------------------------------------------------" << endl;
    LinearSearch(student,height,course,year,5);
    sort(student,height,course,year);
    BinarySearch(student,height,course,year,5);

    return 0;
}
