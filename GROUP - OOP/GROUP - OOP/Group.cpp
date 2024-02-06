#include "Group.h"

    Group::Group()
    {
        SetGroupName("P26");
        SetNumberOfCourse(2);
        SetSpecification("Software Development");
    }

    void Group::Print() 
    {
        cout << group_name << "\n";
        for (int i = 0; i < countstudent; i++)
        {
            classmates[i].PrintStudent();
            classmates[i].AverageGrade();
        }
    }

    void Group::AddStudent(const Student& new_student)
    {
        countstudent++;
        classmates.push_back(new_student);
        
    }

    void Group::WeanStudent(unsigned short index)
    {
        if (index < classmates.size()) {
            classmates.erase(classmates.begin() + index);
            countstudent--;
        }
    }
    void Group::Expel()
    {
        if (countstudent == 0) {
            cout << "The group is empty.\n\n";
            return;
        }
        int minGradeIndex = 0;
        for (int i = 1; i < countstudent; i++)
        {
            if (classmates[i].GetAverageGrade() < classmates[minGradeIndex].GetAverageGrade())
            {
                minGradeIndex = i;
            }
        }
        classmates.erase(classmates.begin() + minGradeIndex); 
        countstudent--;
        cout << "The student with the lowest grade point average is dropped from the group.\n\n";
    }

    void Group::SetCountOfStudent(int countstudent)
    {
        this->countstudent = countstudent;
    }

    int Group::GetCountOfStudent() const
    {
        return countstudent;
    }

    void Group::SetGroupName(string group_name)
    {
        this->group_name = group_name;
    }

    string Group::GetGroupName() const
    {
        return group_name;
    }

    void Group::SetSpecification(string specification)
    {
        this->specification = specification;
    }

    string Group::GetSpecification() const
    {
        return specification;
    }

    void Group::SetNumberOfCourse(int number_of_course)
    {
        this->number_of_course = number_of_course;
    }

    int Group::GetNumberOfCourse() const
    {
        return number_of_course;
    }



