#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>

#include "states.h"


//create the 50 states
State fifty_states[50] = {{.name = "Alabama", .capital = "Montgomery", .dirty_bit = 0},
                          {.name = "Alaska", .capital = "Juneau", .dirty_bit = 0},
                          {.name = "Arizona", .capital = "Phoenix", .dirty_bit = 0},
                          {.name = "Arkansas", .capital = "Little Rock", .dirty_bit = 0},
                          {.name = "California", .capital = "Sacramento", .dirty_bit = 0},
                          {.name = "Colorado", .capital = "Denver", .dirty_bit = 0},
                          {.name = "Connecticut", .capital = "Hartford", .dirty_bit = 0},
                          {.name = "Delaware", .capital = "Dover", .dirty_bit = 0},
                          {.name = "Florida", .capital = "Tallahassee", .dirty_bit = 0},
                          {.name = "Georgia", .capital = "Atlanta", .dirty_bit = 0},
                          {.name = "Hawaii", .capital = "Honolulu", .dirty_bit = 0},
                          {.name = "Idaho", .capital = "Boise", .dirty_bit = 0},
                          {.name = "Illinois", .capital = "Springfield", .dirty_bit = 0},
                          {.name = "Indiana", .capital = "Indianapolis", .dirty_bit = 0},
                          {.name = "Iowa", .capital = "Des Moines", .dirty_bit = 0},
                          {.name = "Kansas", .capital = "Topeka", .dirty_bit = 0},
                          {.name = "Kentucky", .capital = "Frankfort", .dirty_bit = 0},
                          {.name = "Louisiana", .capital = "Baton Rouge", .dirty_bit = 0},
                          {.name = "Maine", .capital = "Augusta", .dirty_bit = 0},
                          {.name = "Maryland", .capital = "Annapolis", .dirty_bit = 0},
                          {.name = "Massachusetts", .capital = "Boston", .dirty_bit = 0},
                          {.name = "Michigan", .capital = "Lansing", .dirty_bit = 0},
                          {.name = "Minnesota", .capital = "Saint Paul", .dirty_bit = 0},
                          {.name = "Mississippi", .capital = "Jackson", .dirty_bit = 0},
                          {.name = "Missouri", .capital = "Jefferson City", .dirty_bit = 0},
                          {.name = "Montana", .capital = "Helena", .dirty_bit = 0},
                          {.name = "Nebraska", .capital = "Lincoln", .dirty_bit = 0},
                          {.name = "Nevada", .capital = "Carson City", .dirty_bit = 0},
                          {.name = "New Hampshire", .capital = "Concord", .dirty_bit = 0},
                          {.name = "New Jersey", .capital = "Trenton", .dirty_bit = 0},
                          {.name = "New Mexico", .capital = "Santa Fe", .dirty_bit = 0},
                          {.name = "New York", .capital = "Albany", .dirty_bit = 0},
                          {.name = "North Carolina", .capital = "Raleigh", .dirty_bit = 0},
                          {.name = "North Dakota", .capital = "Bismarck", .dirty_bit = 0},
                          {.name = "Ohio", .capital = "Columbus", .dirty_bit = 0},
                          {.name = "Oklahoma", .capital = "Oklahoma City", .dirty_bit = 0},
                          {.name = "Oregon", .capital = "Salem", .dirty_bit = 0},
                          {.name = "Pennsylvania", .capital = "Harrisburg", .dirty_bit = 0},
                          {.name = "Rhode Island", .capital = "Providence", .dirty_bit = 0},
                          {.name = "South Carolina", .capital = "Columbia", .dirty_bit = 0},
                          {.name = "South Dakota", .capital = "Pierre", .dirty_bit = 0},
                          {.name = "Tennessee", .capital = "Nashville", .dirty_bit = 0},
                          {.name = "Texas", .capital = "Austin", .dirty_bit = 0},
                          {.name = "Utah", .capital = "Salt Lake City", .dirty_bit = 0},
                          {.name = "Vermont", .capital = "Montpelier", .dirty_bit = 0},
                          {.name = "Virginia", .capital = "Richmond", .dirty_bit = 0},
                          {.name = "Washington", .capital = "Olympia", .dirty_bit = 0},
                          {.name = "West Virginia", .capital = "Charleston", .dirty_bit = 0},
                          {.name = "Wisconsin", .capital = "Madison", .dirty_bit = 0},
                          {.name = "Wyoming", .capital = "Cheyenne", .dirty_bit = 0}};

//intro print statements
void introduction_print_statements() {
    printf("\n--------------------------\n");
    printf("Hello, and welcome!\n");
    printf("This is a game that quizzes you on the state capitals!\n");
    printf("\n--------------------------\n");
    return;
}


int correct_answer(int score){
    printf("\nthat is correct!\n");
    return ++score;
}


int wrong_answer(int score) {
    printf("\nthat is incorrect.\n");
    return score;
}

int prompt_question(int i, int score) {
    char input_string[20];
    printf("What is the capital of %s?\n", fifty_states[i].name);

    //input a string from the user, and replace the \n at the end with \0
    //so that the inputted string is in the proper format to be compared.
    fgets(input_string, sizeof input_string, stdin);
    input_string[strcspn(input_string, "\n")] = '\0';

    if (strcmp(input_string, fifty_states[i].capital) == 0) {
        return correct_answer(score);
    }
    return wrong_answer(score);
;
}


int check_if_asked_before() {

    int question_to_ask = rand() % 50;
    if (fifty_states[question_to_ask].dirty_bit == 1) return check_if_asked_before();
    fifty_states[question_to_ask].dirty_bit = 1;
    return question_to_ask;
}

int main() {
    
    //print the opening statements
    introduction_print_statements();
    
    int score = 0;
    srand(time(0));

    //ask a new question
    for (int questions_asked = 0; questions_asked<50; questions_asked++) {
        int question_to_ask = check_if_asked_before();
        score = prompt_question(question_to_ask, score);
        printf("Score: %d/%d\n\n", score, questions_asked+1);


    }
    return 0;
}