/**
 * @file course.c
 * @author Emaan Khan (khanm345@mcmaster.ca)
 * @brief course.c contains all the functions that involve either accessing or changing the course's information
 * @version 0.1
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "course.h"
#include <stdlib.h>
#include <stdio.h>
 
/**
 * @brief The function enroll_student adds a student to the list of students enrolled within the current course 
 * 
 * @param course A specific course with all its information encolosed within the Course data type
 * @param student A specific student with all its information enclosed within the Student data type
 * @return nothing
 */
void enroll_student(Course *course, Student *student)
{
  course->total_students++;
  if (course->total_students == 1) 
  {
    /** Calloc is used to create an empty list of size one if the number of total students is 1 */
    course->students = calloc(1, sizeof(Student));
  }
  else 
  {
    /** Realloc is used to allocate more space within the list of students to add in a new student */
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student)); 
  }
  course->students[course->total_students - 1] = *student;
}

/**
 * @brief The function print_course prints out the course's name, course code, the total number of students enrolled in the course and each student with all their academic information within the course
 * 
 * @param course A specific course with all its information enclosed within the Course data type
 * @return nothing
 */
void print_course(Course* course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");

  /** This for loop prints out all students that are enrolled in the course */
  for (int i = 0; i < course->total_students; i++) 
    print_student(&course->students[i]);
}

/**
 * @brief The function top_student traverses through the list of students within the course and returns the student with the highest average
 * 
 * @param course A specific course with all its information enclosed within the Course data type
 * @return A specific student with all its information enclosed within the Student data type
 */
Student* top_student(Course* course)
{
  if (course->total_students == 0) return NULL;
 
  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];
  
  /** This for loop iterates through the list of students within the course and keeps in track of the student with the highest average in the course */
  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average) 
    {
      max_average = student_average;
      student = &course->students[i];
    }   
  }

  return student;
}

/**
 * @brief The function passing filters out all the students who are not passing the course
 * 
 * @param course A specific course with all its information enclosed within the Course data type
 * @param total_passing Total number of students passing
 * @return A list of students passing the course with each student enclosed within the Student data type
 */
Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;
  
  /** This for loop counts all the students passing the course */
  for (int i = 0; i < course->total_students; i++) 
    if (average(&course->students[i]) >= 50) count++;
  
  /** Calloc is used to initialize a list of students with the size of count (which is the number of students passing)*/
  passing = calloc(count, sizeof(Student));

  int j = 0;

  /** This for loop adds all the students passing the course to a list*/
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++; 
    }
  }

  *total_passing = count;

  return passing;
}