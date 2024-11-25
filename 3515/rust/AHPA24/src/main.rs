fn main() { // Some fun with vectors
    let mut students: Vec<(&str, i32)> = vec![("Tim", 79), ("Mary", 92), ("Tom", 83), ("Jane", 87), ("Ann", 75)];
    vec_print(&students);
    students = round(students);
    println!();
    vec_print(&students);
}

fn round(mut students: Vec<(&str, i32)>) -> Vec<(&str, i32)> { // WHO ROUNDS LIKE THIS?!
    for i in 0..students.len() {
        students[i].1 += 5;
    }
    students
}

fn vec_print(students: &Vec<(&str, i32)>) { // Yes, my comedy is back
    for (name, grade) in students {
        println!("Student {} has a score of {}.", name, grade);
    }
}
