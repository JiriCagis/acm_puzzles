#include<iostream>
#include<vector>
#include<map>
using namespace std;



void printInputs(int countCourses, int countStudents, bool assignStudents[], map<int,vector<int>> courseToStudentsMap)
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
	for(map<int,vector<int>>::iterator it=courseToStudentsMap.begin(); it != courseToStudentsMap.end(); it++)
	{
		cout << "CourseId: " << it->first << "\n";
		cout << "*************************************\n";

		vector<int> students = it->second;
		for(vector<int>::iterator studentIt=students.begin(); studentIt != students.end(); studentIt++)
		{
			cout << "StudentId: " << *studentIt << "\n";
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

bool existCombinationOfStudentsForBuildCommittee(int countCourses, int countStudents, bool *assignStudents, map<int,vector<int>> courseToStudentsMap)
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
		
		map<int,vector<int>> courseToStudentsMap;
		bool *assignStudents = new bool[countStudents];
		
		for (int i=0;i<=countStudents;i++)
		{
			assignStudents[i] = false;
		}
		
		for(int courseId =0;courseId < countCourses;courseId++)
		{
			int countStudentsInCourse = 0;
			cin >> countStudentsInCourse;
			vector<int> students(countStudentsInCourse);
			for(int i=0;i<countStudentsInCourse;i++){
				int studentId = 0;
				cin >> studentId;
				studentId--; //increment id, because array start from position zero
				students[i]  = studentId;
				assignStudents[studentId] = true;
			}
			
			courseToStudentsMap[courseId]=students;
		}
		
		printInputs(countCourses,countStudents,assignStudents,courseToStudentsMap);
			
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

