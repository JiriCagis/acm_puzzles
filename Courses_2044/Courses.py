
class Courses:
	
	def __init__(self, count_students, count_courses):
		self.count_students = count_students;
		self.count_courses = count_courses;
		self.studentToCoursesMap = {};
		self.courseToStudentsMap = {};

	def assign_student_to_course(self, student_id, course_id):
		pass;

	def exist_combination_of_students_for_build_committe(self):
		return "YES";



if __name__ == "__main__":
	courses = Courses(3,3);
	print("Count students: " + str(courses.count_students));
	print("Count courses: " + str(courses.count_courses));	
