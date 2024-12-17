#include <stdio.h>
#include "utils.c"
#include "grade_calculator.c"
#define NUM_STUDENTS 3
struct Student {
	char name[30];
	float score;
};

int main()
{
	struct Student students[NUM_STUDENTS] = {
	{"Leyla", 99.9},
	{"Nigar", 81.1},
	{"Nargiz", 63.3}
	};

	float scores[NUM_STUDENTS];

	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		char grade = calculate_grade(students[i].score);
		printf("%s: Score = %.2f, Grade = %c\n", students[i].name, students[i].score, grade);

	scores[i] = students[i].score;
	}

	float average = calculate_average_score(scores, NUM_STUDENTS);
	printf("Average score of all students: %.2f\n", average);

	return (0);
}
