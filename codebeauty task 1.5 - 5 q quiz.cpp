//A 5 question quiz that asks the user for input one after the other.  The answers of the user
//are stored within this source file (the program), and compared with the user's answer to each
//question.
//User is given the results of their answers after each question, and then perhaps a tally is made at the end.
//From this video - https://www.youtube.com/watch?v=9j5KkOC_goQ

//The question is a struct, with two members - text of the question and array of the multiple choice
//answers.
//Answer is a struct too with an indication of if its correct or incorrect.
//There are 5 questions, and each question should increment a for loop after the user gives an answer
//in order to bring up the next question.
//You could upgrade the app with multiple users, money prizes, levels, etc.


/*
PSEUDO

struct question
{
text
array for multichoice
};

struct answer
{
stores answer to each question in an array
};

answer_check
{
output correct or incorrect based on answer.correctflag
}

main()
{
create 5 objects of question
fill out multichoice array and text for each question

for loop
{
output question object text and multichoice 1 to 3

if(i = some_number)
    output the corresponding question object text and multichoice

1. separate function to read user answer, perhaps the answer() function,
2. which will store and compare the user answer as well,
3. then mark correctflag true or false and output correct or wrong
NOTE: probably no need for answer_check it might be able to just store user input
and compare it within the struct or the function.  You should preserve answer as a struct.
The function will gather user input.  The answer should be stored in the struct.
}

}*/

#include <iostream>
#include <string>
#include <stdlib.h>


struct question  //I suppose a function might fill out these values, but I don't like messing around with scope if I don't need to.  Method maybe, but methods don't belong in structs
{
    std::string text;  //text filled in main
    std::string multichoice[3];  //multiple choice is filled out in main
};


struct answer  //this one only has one object associated, compared to the 5 of question
{
    const std::string correct[5] = {"c", "c", "b", "a", "c"};  //contains the correct answers
    std::string user_answer[5];  //stores user answers, begins empty for fill of user_input
};

int main()
{
    question q1, q2, q3, q4, q5; //each question has its own text and multiple choice, thus needing 5 objects for the 5 questions
    answer a; //only one object, since it only checks the 5 const correct answers and stores validated user input
    int score = 0;

    q1.text = "Q1. What is the capitol of Iceland?";  //filling out all the values, from q1 to q5
    q1.multichoice[0] = "A. Gayohvik\n";
    q1.multichoice[1] = "B. Iceohmar\n";
    q1.multichoice[2] = "C. Reyjavik\n";

    q2.text = "\nQ2. Why are lions gay?";
    q2.multichoice[0] = "A. Um... because they're not homophobic?  You bigot\n";
    q2.multichoice[1] = "B. Lions aren't gay, you're gay\n";
    q2.multichoice[2] = "C. Male gayness reduces competition with the alpha, potentially benefiting \n   the herd evolutionarily, albeit sacrificing the individual to be childless.\n";

    q3.text = "\nQ3. What does 'as the crow flies' mean?";
    q3.multichoice[0] = "A. \"It means you're gay!\"  Quoth the crow in its cawing crow-speech.\n";
    q3.multichoice[1] = "B. The direction from one point on a map to another, if you were to draw a straight line between those points.\n";
    q3.multichoice[2] = "C. It's poetry that evokes the beauty of the crow in flight... or something.  It uh - it just sounds nice, okay?\n";

    q4.text = "\nQ4. Why, in Lord of the Rings, did Sauron want power?";
    q4.multichoice[0] = "A. He was a consequentialist seeking to improve Middle Earth's GDP and create jobs, in effect.\n";
    q4.multichoice[1] = "B. \"Gay was he, and lo, for another name for him was the gay lord.\"  \n   I'm pretty sure Gandalf said that to Frodo one time.\n";
    q4.multichoice[2] = "C. He was misunderstood and wanted to redeem himself from his evil ways, but Galadriel broke his heart.\n   Therein, the fires of hatred for all things fueled him forever more.\n";

    q5.text = "\nQ5. What... is your favourite colour?";
    q5.multichoice[0] = "A. Yellow?\n";
    q5.multichoice[1] = "B. Rainbow, because that's all colours, so I'm bound to hit the right one.\n";
    q5.multichoice[2] = "C. Blue, because it's also the programmer's favourite colour.\n";  //final value to be filled

    question qarray[5] = {q1, q2, q3, q4, q5};  //storing the q objects in an array for looping through

    std::string user;  //user input is a string so that it doesn't error and crash the program if they input more than one char... instead it will ask them to enter again
    bool x;  //flag tells while when to quit
    std::string arrayl;

//    for (int i = 0; i<qarray.end(); i++)
//    {
//        array1+=qarray[i];
//    }

    for(int i = 0; i<5; i++)
    {
        x = false;

        std::cout << qarray[i].text << std::endl;  //displaying each question in order of q1 to q5
        std::cout << qarray[i].multichoice[0];
        std::cout << qarray[i].multichoice[1];
        std::cout << qarray[i].multichoice[2];  //too many newlines, so I got rid of the endl for multichoice printing

        while (x == false)
        {
            std::cin >> user;
            user[0] = tolower(user[0]);  //lowercase user to halve the number of chars to compare... only lowered first element of input, since user should only input one letter anyway

            if (user != "a" && user != "b" && user != "c")  //checks if user input is not valid
            {
                std::cout << "Answer must be a, b, or c." << std::endl;  //tells user to input again if invaild.  It's convenient that I didn't have to flush cin here
            }
            else  //user input is not not valid, AKA valid
            {
                x = true;
                a.user_answer[i] = user;  //one element of user_answer array is filled with user input

                if (a.user_answer[i] == a.correct[i])  //is user input correct?
                {
                    std::cout << "Correct!" << std::endl;
                }
                else  //no?  okay, it's incorrect then (obviously)
                {
                    std::cout << "Incorrect." << std::endl;
                }
            }
        }
//        std::cout << "Answer: " << a.correct[i] << std::endl;  //PRINT TEST
//        std::cout << "User answer: " << a.user_answer[i] << std::endl;  //PRINT TEST
    }


    for(int i = 0; i <5; i++)  //tallies up score by checking if correct again, for each user answer
    {
        if (a.user_answer[i] == a.correct[i])
        {
            score++;
        }
    }

    std::cout << "\nFinal Score: " << score << " out of 5 answers were correct.  ";  //score print

    if (score == 5)
    {
        std::cout << "Conglaturation!  A winner is you." << std::endl;
    }
    else
    {
        std::cout << "Try again next time." << std::endl;
    }
}



