#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {

    // Initialization of "Names" file

    /*
     * Creating array of name "aName" and with memory of 829, which is number of names in the file
     * Creating loop that starts from 0
     * Creating string to store the name from the particular line
     * Creating file stream input with custom name "oName" and reading the "names" file
     */

    string aName[829];
    long loop1 = 0;
    string name;
    ifstream oName("names");

    /*
     * Condition checks whether the file is opened or not, and if it is, it will do following:
     * While the file is didn't reach the end of file, do next:
     * get line of the file and store it's name into the string from line 21
     * file will be on the loop and store each name into string until the end of line, 1 by 1
     * file will close after it reaches the end
     * Else, if the file cannot open at all, it will print it out for user
     */
    if (oName.is_open())
    {
        while (!oName.eof()) {
            getline(oName, name);
            aName[loop1] = name;
            // loop increments until end of file
            loop1++;
        }
        oName.close();
    }
    else{
        cout << "Cannot load file: Names";
        cout<<endl;
    }

    // Initialization of "Gender" file

    /*
     * Creating array for genders with size 829
     * Creating loop starting from 0
     * Creating string to store the line from file
     * Since the file "Gender" stores binary values (1 for male, 0 for female), I created strings s1 and s2 to store binary data
     * sex1 and sex0 are used as converting binary to string
     * Loading file via ifstream and naming it "gender"
     * if/while loop is same as previous one with names, only in this case we have additional nested if case for gender naming
     * if is conditioned to compare file values (1 and 0) and storing them as a string (male and female) - if 1 -> male, if 0-> female
     * After the file has been read through, file closes, otherwise if the file wasn't able to load, it will print it out
     * This part of code isn't required by the task, but it will be used beneath in "case 2"
     */

    string aSex[829];
    long loop2 = 0;
    string sex;
    string s1 = "1";
    string s2 = "0";
    string sex1 = "Male";
    string sex0 = "Female";
    ifstream gender("gender");

    if (gender.is_open())
    {
        while (!gender.eof())
        {
            getline(gender, sex);
            aSex[loop2] = sex;

            //converting binary to string value
            if(aSex[loop2] == s1){
                aSex[loop2] = sex1;
            }
            else if(aSex[loop2] == s2){
                aSex[loop2] = sex0;
            }
            // loop increments until the end of file
            loop2++;
        }

        gender.close();
    }
    else{
        cout << "Cannot load file: Gender";
        cout<<endl;
    }

    // Initialization of "Crimes" file

    /*
     * Creating 2 vectors (similar to arrays) to store both columns from the "Crimes" file and naming them vec1 and vec2
     * integers 'a' and 'b' will store values from left and right column respectively
     * We initialize the file via ifstream and naming it "crime" and loading "crime" file
     * Condition checks if the file is opened, and if yes, do following:
     * Read the file and load columns 'a' and 'b'
     * push_back() function is used to push elements into a vector from the back.
     * outside of while loop, file closes after reaching the end of file
     * in case of file being unable to open, it prints it out
     */

    vector<int> vec1;
    vector<int> vec2;
    int a, b;

    ifstream crime("crime");

    if (crime.is_open())
    {
        while (!crime.eof())
        {
            crime >> a >> b;
            vec1.push_back(a);
            vec2.push_back(b);
        }
        crime.close();
    }
    else{
        cout << "Cannot load file: Crime";
        cout<<endl;
        }

    // Initialization of "Role" file

    /*
     * Exact code as for "aName" part, only with different variable names
     * Only in this situation, apart from "aName" code, array size for this has size of 1476
     * This part is only initialized, but we won't use it anywhere in code since it's not requested to be used
     */

    string aRole[1476];
    long loop3 = 0;
    string roles;
    ifstream role("role");

    if (role.is_open())
    {
        while (!role.eof())
        {
            getline(role, roles);
            aRole[loop3] = roles;
            loop3++;
        }
        role.close();
    }
    else{
        cout << "Cannot load file: Role";
        cout << endl;
    }


    //   Beginning of execution

    /*
     * Defining variable input of type integer, which will be entered by user to choose from menu below:
     * do { will keep executing the code from there until it reaches certain "while", then it will stop
     */

    int input;
    do {
        // This is the main menu from switch case, which will allow user to select his choice
        cout << "Enter which part You want to execute:      (or type 0 to exit)" << endl;
        cout << endl;
        cout << "1. Calculate the average number of crimes a person is involved in." << endl;
        cout << "2. Calculate the maximum number of crimes a single person is involved in." << endl;
        cout << "3. Calculate the average number of people involved in a crime." << endl;
        cout << "4. Calculate the maximum number of people involved in a single crime." << endl;
        cout << endl;
        cin >> input;

        while (input < 1 || input > 4)     // while the input from user is not 1-4, it will repeat until valid choice is entered
        {
            if(input==0){                  // only exception for this loop to end is to input 0
                return 0;
            } else
            cout << "Please enter a valid option (1-4) or 0 to exit." << endl << endl;
            cin >> input;
        }

        // Beginning of switch menu
        switch (input)
        {
            /*
             * If user inputs 1, case 1 executes
             * Array of double is created with size 829 for names
             * First for loop starts from 1 and goes through all people until 829, counter is set at 0 at first
             * Nested for loop starts from 0 and runs until it reaches maximum size from vec1 (mentioned earlier), counting crimes associated with people
             * counter will increase until the end of file, which is vector 1's size
             * P1[i] will count all number of crimes committed
             * average of double is set as 0
             * another for loop starts from 0 and goes until end of people while incrementing for each new appearance
             * average will be set as array of p1 of 'l' loop + itself, to sum up all crimes
             * the final number stored in average will be divided by number of people and it will be printed out
             * case 1 will end and we return to main menu, since this average will never change
             */

            case 1:
            {
                double p1[829];

                for (int i = 1; i <= 829; i++) {
                    double count1 = 0;

                    for (int k = 0; k <= vec1.size(); k++) {
                        if (i == vec1[k])
                            count1++;
                    }
                    p1[i] = count1;
                }

                double average = 0;

                for (int l = 0; l <= 829; l++)
                    average += p1[l];

                average /= 829;
                cout << endl;
                cout << "The average number of crimes a person is involved in is " << average << endl << endl;
                break;
            } // End of case 1

            /*
             * Case 2 allows user to check up person's ID and see how many crimes that person is involved in
             * integer x which will be entered by user, which represents ID of person we look up
             * another do-while nested inside case 2, allows user to circulate and enter new IDs for check until we exit to main menu
             * For loops same as in previous case, circulating through names and crimes of particular ID
             * if inputted number equals the ID that user is looking for, it prints out the result
             * aName[x-1] represents person's name, and -1 is used to get 1 name before our inputted number, since array starts from 0 (same for aSex[x-1])
             * while in the end serves as a loop for as long as the user is entering numbers from 1 to 829, otherwise the case ends
             */

            case 2:
            {
                int x;

                do{
                    cout << "Enter persons' number (1-829) or 0 to exit to main menu" << endl;
                    cin >> x;

                    for (int i = 1; i <= 829; i++) {
                        double count2 = 0;
                        for (int k = 0; k <= vec1.size(); k++) {
                            if (i == vec1[k])
                                count2++;
                        }
                        if (x == i) {
                            cout << endl;
                            cout << "Person with ID "<< x << ", "<<aName[x-1] << ", Gender: " << aSex[x-1] << ", was involved in " << count2 << " number of crimes." << endl <<endl;
                        }
                    }

                } while (x > 0 && x < 830);
                break;
            } // End of case 2

            /*
             * Same code as for the "case 1", except for that instead of 829 (number of people) we set 551, which is maximum number of crime
             * Also, the array size is 1476, because that's the total number of crimes that people were part of
             * in the average part, we divide the summed number of crimes and divide by max value (551)
             * After it prints it out, we break out of the case, since the value doesn't change (unless we purposely change the value of 551)
             */

            case 3:
            {
                double p3[1476];

                for (int i = 1; i <= 551; i++) {
                    double count3 = 0;
                    for (int k = 0; k <= vec2.size(); k++) {
                        if (i == vec2[k])
                            count3++;
                    }
                    p3[i] = count3;
                }

                double avg_crime = 0;

                for (int l = 0; l <= 551; l++)
                    avg_crime += p3[l];

                avg_crime /= 551;
                cout << endl;
                cout << "The average number of people involved in a crime is " << avg_crime << endl << endl;
                break;
            } // End of case 3

            /*
             * code same as for "case 2", except for in this case user enters crime number 1-551 to print out how many people were involved in it
             * integrated do-while to circulate as long as user is inputting valid numbers, 0 exits to main menu
             * user inputs 'num' value, nested loops circulate through the crimes until it hits aimed value, afterwards it counts number of people involved
             * after the execution, user is sent back to input a number, unless if 0 is entered, it returns to main menu
             */
            case 4:
            {
                double p4[551];
                int num;
                do {
                    cout << "Enter the number of the crime (1-551) or 0 to exit to main menu:" << endl << endl;
                    cin >> num;

                    for (int i = 1; i <= 551; i++) {
                        double max = 0;
                        for (int k = 0; k <= vec2.size(); k++) {
                            if (i == vec2[k])
                                max++;
                        }
                        if (num == i) {
                            cout << endl;
                            cout << "Number of people involved in crime " << num << " was " << max <<endl << endl;
                            p4[i] = max;
                        }
                    }
                } while (num > 0 && num < 552);
                break;
            }  // End of case 4

            // In case we enter invalid menu option, user is told which are his available options
            default:
                cout << "Please enter number 1-4! (or type 0 to exit)";
                break;
        }  // End of Switch

    } while(input <= 4 && input >= 1); // End of "do{" loop from line 167, which repeats itself while user is entering valid menu options (1-4) or unless we exit (enter 0)

    return 0;      // End of program - exiting

}   //end of main() function