import unittest;
from Courses import Courses;


class CoursesTest(unittest.TestCase):
	
	def test_combinnation_build_committe_01(self):
		courses = Courses(1,1);
		courses.assign_student_to_course(1,1);
		result = courses.exist_combination_of_students_for_build_committe();
		self.assertEqual("YES",result);

	def test_combination_not_build_committe_01(self):
		courses = Courses(1,1);
		result = courses.exist_combination_of_students_for_build_committe();
		self.assertEqual("NO",result);

	def test_combination_not_build_committe_02(self):
		courses = Courses(2,15);
		courses.assign_student_to_course(1,1);
		




if __name__ == "__main__":
	unittest.main();
