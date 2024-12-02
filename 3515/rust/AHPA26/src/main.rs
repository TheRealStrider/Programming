enum Student { // Enums are cool
    Freshman(String),
    Sophomore(f64),
    Junior(bool),
    Senior(bool),
}

impl Student { // Implementing a method for the enum
    fn print(&self) {
        match self {
            Student::Freshman(name) => println!("Student info: Freshman(\"{}\")", name),
            Student::Sophomore(gpa) => println!("Student info: Sophomore({})", gpa),
            Student::Junior(has_intern) => println!("Student info: Junior({})", has_intern),
            Student::Senior(has_job) => println!("Student info: Senior({})", has_job),
        }
    }
}

fn main() { // We are back
    let student1 = Student::Freshman(String::from("Tim Johnson"));
    let student2 = Student::Sophomore(3.3);
    let student3 = Student::Junior(false);
    let student4 = Student::Senior(true);

    student1.print();
    student2.print();
    student3.print();
    student4.print();

} // Ended so soon
