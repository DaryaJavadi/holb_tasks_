#include "grade_calculator.h"
char calculate_grade(float score)
{
	if (score > 90)
	{
		return 'A';
	}
	else if (80 < score <= 90)
	{
		return 'B';
	}
	else if (70 < score <= 80)
	{
		return 'C';
	}
	else if (60 < score <= 70)
	{
		return 'D';
	}
	else if (50 < score <= 60)
	{
		return 'E';
	}
	else
	{
		return 'F';
	}
}
