#include<iostream>
using namespace std;



void printInputs(int countCourses, int countStudents, bool assignStudents[], int* courseToStudentsMap[])
{
	cout << "Count courses: " << countCourses << "\n";
	cout << "Count students: " << countStudents << "\n";
	cout << "\n";
	
	cout << "Assigned students:\n";
	for (int i=1;i<=countStudents;i++)
	{
		cout << "Student id: " << i << " is assigned to any course: " << (assignStudents[i]==1?"True":"False") << "\n";
	}
	
	cout << "\nCourses:\n";
	for (int courseId=0; courseId<countCourses;courseId++){
		int* students= courseToStudentsMap[courseId];
		int sizeOfStudents = students[0];
		cout << "CourseId: " << courseId << "\n";
		cout << "*************************\n";
		for(int j=1;j<=sizeOfStudents;j++)
		{
			cout << "studentId:" << students[j] << "\n";
		}
		cout << "\n";
	}
}

int computeCountAssignStudents(bool *assignStudents, int countStudents)
{
	int count = 0;
	
	for (int i=0; i<=countStudents; i++)
	{
		if (assignStudents[i] == 1)
		{
			count++;
		}
	}	
	return count;
}

bool existCombinationOfStudentsForBuildCommittee(int countCourses, int countStudents, bool *assignStudents, int **courseToStudentsMap)
{
	if (countStudents < countCourses)
	{
		return false;
	}
	
	if(countCourses > computeCountAssignStudents(assignStudents,countStudents))
	{	
		return false;
	}

	return true;
}


int main()
{
	int countRepeats = 0;
	int repeat = 0;
	
	cin >> countRepeats;
	while(repeat++ < countRepeats)
	{

		// Load data from input
		int countStudents = 0;
		int countCourses = 0;
		
		cin >> countStudents;
		cin >> countCourses;
		
		int **courseToStudentsMap = new int*[countCourses];
		bool *assignStudents = new bool[countStudents+1];
		for (int i=0;i<=countStudents;i++)
		{
			assignStudents[i] = false;
		}
		
		for(int courseId =0;courseId < countCourses;courseId++)
		{
			int countStudentsInCourse = 0;
			cin >> countStudentsInCourse;
			int* students = new int[countStudentsInCourse+1];
			students[0]=countStudentsInCourse;
			for(int i=1;i<=countStudentsInCourse;i++){
				int studentId = 0;
				cin >> studentId;
				students[i] = studentId;
				assignStudents[studentId] = true;
			}
			
			courseToStudentsMap[courseId]=&students[0];
		}
		
		// Compute if exist committee
		if(existCombinationOfStudentsForBuildCommittee(countStudents,countCourses,assignStudents,courseToStudentsMap))
		{
			cout << "YES" << "\n";
		}
		else
		{	
			cout << "NO" << "\n";
		}
		//Clear data
		
	}
	
	return 0;
}

