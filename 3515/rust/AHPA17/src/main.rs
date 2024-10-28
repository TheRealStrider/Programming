fn main() {
    let student1: ( &str, i32, f64) = ("Mark Johnson", 75, 79.5);
    let student2: ( &str, i32, f64) = ("Ann Tran", 52, 83.2);
    let student3: ( &str, i32, f64) = ("Susan Anthony", 101, 91.4);

    println!("1 Student {0} has rank {1} and test score {2}.", student1.0, student1.1, student1.2);
    println!("2 Student {0} has rank {1} and test score {2}.", student2.0, student2.1, student2.2);
    println!("3 Student {0} has rank {1} and test score {2}.", student3.0, student3.1, student3.2);
}
