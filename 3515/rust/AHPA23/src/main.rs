#[derive(Debug)]
#[allow(dead_code)]
struct Player {
    name: String,
    game_name: String,
    age: i32,
    level: i32,
}

fn main() { // THIS TOOK ME FOREVER
    let player1 = player_info(&String::from("Bob Johnson:Master Sergeant:21:7"));
    let player2 = player_info(&String::from("Rebecca Hold:Slay:19:4"));
    let player3 = player_info(&String::from("John Majors:Murader:20:6"));
    let player4 = player_info(&String::from("Ann Jenkins:Force:22:9"));

    println!("{:?}", player1);
    println!("{:?}", player2);
    println!("{:?}", player3);
    println!("{:?}", player4);
}

fn player_info(player_data: &String) -> Player {
    let mut player_bytes = player_data.as_bytes();
    let mut name = "";
    let mut game_name = "";
    let mut age = 0;
    let level;

    for j in 0..3 {
        for (i, &item) in player_bytes.iter().enumerate() {
            if item == b':' {
                match j {
                    0 => name = std::str::from_utf8(&player_bytes[..i]).unwrap(),
                    1 => game_name = std::str::from_utf8(&player_bytes[..i]).unwrap(),
                    2 => age = std::str::from_utf8(&player_bytes[..i]).unwrap().parse().unwrap(),
                    _ => (),
                }
                player_bytes = &player_bytes[i + 1..];
                break;
            }
        }
    }
    level = std::str::from_utf8(&player_bytes).unwrap().parse().unwrap();

    Player {
        name: name.to_string(),
        game_name: game_name.to_string(),
        age,
        level,
    }
}
