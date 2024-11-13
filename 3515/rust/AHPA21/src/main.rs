fn main() { // I hate formatting command outputs >:(
    println!("Index  Squared  Even/Odd  Cubed  Even/Odd");
    println!("-----  -------  --------  -----  --------");

    for i in 1..=10 {
        let squared = squared(i);
        let cubed = cubed(i);
        let even_or_odd_squared = is_even_or_odd(squared);
        let even_or_odd_cubed = is_even_or_odd(cubed);
        if i < 10 {
            print!("  {}", i);
        }
        else {
            print!(" {}", i);
        }

        if squared < 10 {
            print!("        {}", squared);
        }
        else if squared < 100 {
            print!("       {}", squared);
        }
        else {
            print!("      {}", squared);
        }

        if even_or_odd_squared == "Even" {
            print!("      {}  ", even_or_odd_squared);
        }
        else {
            print!("      {}   ", even_or_odd_squared);
        }

        if cubed < 10 {
            print!("      {}", cubed);
        }
        else if cubed < 100 {
            print!("     {}", cubed);
        }
        else if cubed < 1_000{
            print!("    {}", cubed);
        }
        else {
            print!("   {}", cubed);
        }

        println!("     {}", even_or_odd_cubed);
    }
}

fn squared(x: i32) -> i32 {
    x * x
}

fn cubed(x: i32) -> i32 {
    squared(x) * x
}

fn is_even_or_odd(x: i32) -> String {
    if x % 2 == 0 {
        String::from("Even")
    } else {
        String::from("Odd")
    }
}