fn main() {
    let computers = ["Red", "Blue", "Green", "Purple"];
    let mut students = vec!["Bob", "Jane", "Ann", "Tony"];
    let mut i = 0;
    while i < students.len() {
        println!("Student {} has been assigned computer {}.", students[i], computers[i]);
        i += 1;
    }
    i = 0;
    students.remove(2);
    println!();
    while i < students.len() {
        println!("Student {} has been assigned computer {}.", students[i], computers[i]);
        i += 1;
    }
}
