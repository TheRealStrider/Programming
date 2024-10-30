fn main() { // Sometimes I wonder if all Rust programmers actually like crabs
    let last_name1: &str = "Johnson"; // Snake case is less superior to camel case
    let last_name2: &str = "Andrews";
    println!("Testing to see if lastName1 is Johnson and lastName2 is Andrews");
    assert!(last_name1 == "Johnson" && last_name2 == "Andrews");
    println!("Test passed!");

    let first_name1: &str = "Ann";
    #[allow(unused_variables)] // The compiler is afraid of unused variables
    let first_name2: &str = "Joe";
    #[allow(unused_variables)]
    let old_enough1: bool = true;
    let old_enough2: bool = false;
    println!("Testing to see if firstName1 is Ann and oldEnough2 is false");
    assert!(first_name1 == "Ann" && !old_enough2);
    println!("Test passed!");
} // Turns out I do like crabs, but I also like Rust
