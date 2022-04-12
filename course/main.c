/**
 * @file main.c
 * @author Emaan Khan (khanm345@mcmaster.ca)
 * @brief main.c is the primary program that runs all the librarys and functions
 * @version 0.1
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"

/**
 * @brief The main function runs the entire program
 * 
 * @return integer 0
 */
int main()
{
  srand((unsigned) time(NULL));

  /** Course MATH101 is assigned the Course datatype, with its name and code also being initilized */
  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  /** This for loop generates 20 random students and enrolls them into MATH101 */
  for (int i = 0; i < 20; i++) 
    enroll_student(MATH101, generate_random_student(8));
  
  print_course(MATH101);

  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);

  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");

  /** This for loop prints out all the students passing the course */
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);
  
  return 0;
}