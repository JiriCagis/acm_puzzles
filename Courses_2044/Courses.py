
class Courses:
	
        def __init__(self, count_students, count_courses):
                self.count_students = count_students;
                self.count_courses = count_courses;
                self.student_to_courses_map = {};
                self.course_to_students_map = {};

        def assign_student_to_course(self, student_id, course_id):
                if student_id in self.student_to_courses_map:
                        set_of_courses = self.student_to_courses_map[student_id];
                        set_of_courses.add(course_id);
                else:
                        set_of_courses = set();
                        set_of_courses.add(course_id);
                        self.student_to_courses_map[student_id] = set_of_courses;

                if course_id in self.course_to_students_map:
                        set_of_students = self.course_to_students_map[course_id];
                        set_of_students.add(student_id);
                else:
                        set_of_students = set();
                        set_of_students.add(student_id);
                        self.course_to_students_map[course_id] = set_of_students;
                

        def exist_combination_of_students_for_build_committee(self):
                if self.count_students < self.count_courses \
                   or not self.__are_open_all_courses() \
                   or not self.__is_assigned_more_or_equal_studens_as_courses():
                        return "NO";
                
                return "YES";

        def __are_open_all_courses(self):
                count_open_courses = len(self.course_to_students_map.keys());
                if self.count_courses == count_open_courses:
                        return True;
                else:
                        return False;

        def __is_assigned_more_or_equal_studens_as_courses(self):
                count_assigned_students = len(self.student_to_courses_map.keys());
                if count_assigned_students >= self.count_courses:
                        return True;
                else:
                        return False;
                



if __name__ == "__main__":
        numberSteps = NumberSteps();
        countRepeats = int(input());
        repeat = 0;
        while repeat < countRepeats:
                rawString = input();
                point = Point.make_instance_from_raw_string(rawString);
                print(numberSteps.get_number_on(point));
                repeat+=1;
        
        courses = Courses(3,3);
        print("Count students: " + str(courses.count_students));
        print("Count courses: " + str(courses.count_courses));	
