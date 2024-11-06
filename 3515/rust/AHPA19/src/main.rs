fn main() {
    let children_bowling_balls = ["red", "green", "yellow", "blue", "purple"];
    let mut adult_bowling_balls = vec!["gold", "black", "silver", "aqua", "pink", "brown"];
    adult_bowling_balls.push("lavender");
    println!("Children's bowling balls:");
    for ball in children_bowling_balls.iter() {
        println!("{}", ball);
    }
    println!("\nAdult's bowling balls:");
    for ball in adult_bowling_balls.iter() {
        println!("{}", ball);
    }
}
