fn main() { // Sometimes I wonder if people actually read these comments
    let mut the_string:String = String::from("Christmas ");
    println!("String: {}, Length: {}", the_string, the_string.len());
    the_string.push('T');
    println!("String: {}, Length: {}", the_string, the_string.len());
    the_string.push('r');
    println!("String: {}, Length: {}", the_string, the_string.len());
    the_string.push('e');
    println!("String: {}, Length: {}", the_string, the_string.len());
    the_string.push('e');
    println!("String: {}, Length: {}\n", the_string, the_string.len());

    let mut new_string = String::from("Christmas ");
    println!("String: {}, Length: {}", new_string, new_string.len());
    new_string.push_str("Lights");
    println!("String: {}, Length: {}", new_string, new_string.len());

} // I'm not sure if I should be worried about the fact that I'm talking to myself in these comments
