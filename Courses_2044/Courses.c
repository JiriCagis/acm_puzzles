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
		cout << "Student id: " << i << " is assigned to course: " << assignStudents[i] << "\n";
	}
	
	cout << "\nCourses:\n";
	for (int courseId=0; courseId<countCourses;courseId++){
		int* students= courseToStudentsMap[courseId];
		int sizeOfStudents = students[0];
		cout << "Size of students: " << sizeOfStudents << "\n";
//		for(int j=1;j<=sizeOfStudents;j++)
//		{
//			cout << "CourseId: " << courseId << " studentId" << students[j] << "\n";
//		}
	}
}

bool existCombinationOfStudentsForBuildCommittee(int countCourses, int countStudents, bool assignStudens[], int* courseToStudentsMap)
{
	
}

int main()
{
	int countRepeats = 0;
	int repeat;
	
	cin >> countRepeats;
	while(repeat++ < countRepeats)
	{
		int countStudents = 0;
		int countCourses = 0;
		
		cin >> countStudents;
		cin >> countCourses;
		
		int* courseToStudentsMap[countCourses];
		bool assignStudents[countStudents+1] = {false};
		
		for(int courseId =0;courseId < countCourses;courseId++)
		{
			int countStudentsInCourse = 0;
			cin >> countStudentsInCourse;
			int students[countStudentsInCourse+1];
			students[0]=countStudentsInCourse;
			for(int i=1;i<=countStudentsInCourse;i++){
				int studentId = 0;
				cin >> studentId;
				students[i] = studentId;
				assignStudents[studentId] = true;
			}
			
			courseToStudentsMap[courseId]=students;
		}
		
		for (int courseId=0; courseId<countCourses;courseId++){
			int* students= courseToStudentsMap[courseId];
			int sizeOfStudents = students[0];
			cout << "Size of students: " << sizeOfStudents << "\n";
		}
		printInputs(countCourses,countStudents,assignStudents,courseToStudentsMap);
	}
	
	return 0;
}

