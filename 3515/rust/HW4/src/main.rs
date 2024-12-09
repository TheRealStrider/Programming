/*
* COP 3515 – Fall 2024
*
* Homework #4:
*
* Aiden Peyton
*/
use rand::Rng;
use std::fs::File;
use std::io::{Read, Write};

fn main() {
    // PART 1
    let p:i32 = 6;
    let q:i32 = 18;
    let n:i32 = p*q;
    let t:i32 = (p-1) * (q-1);
    let mut rng = rand::thread_rng();
    let mut e: i32;
    loop {
        let m: u8 = rng.gen();
        e = m as i32;
        if gcd(e, t) == 1  && e < t && e > 1{
            if gcd(e, n) == 1 {
                break
            }
        }
    }
    let mut d: i32 = 0;
    for i in 0..20 {
        if (((1 + (i * t)) as f64 / e as f64) * 10.0) % 10.0 == 0.0  && ((1 + (i * t)) as f64 / e as f64) != e as f64 {
            d = ((1 + (i * t)) as f64 / e as f64) as i32;
            break
        }
    }
    println!("e = {}, d = {}, n = {}, t = {}", e, d, n, t);

    let public_key = File::create("public_key.txt").expect("Unable to create");
    write_to_file(public_key, &e, &n);
    let private_key = File::create("private_key.txt").expect("Unable to create");
    write_to_file(private_key, &d, &n);

    // PART 2
    let message = "The greatest discovery of all time is that a person can change his future by merely changing his
attitude";
    let mut from_public = File::open("./public_key.txt").expect("No file");
    let mut pub_data = String::new();
    from_public.read_to_string(&mut pub_data).expect("Unable to read");
    let (new_e, new_n) = key_byte_to_numbers(pub_data);
    let encrypted_message = encrypt(new_e, new_n, message);
    println!("Cypher-text: {:?}", encrypted_message);

    // PART 3
    let mut from_private = File::open("./private_key.txt").expect("No file");
    let mut priv_data = String::new();
    from_private.read_to_string(&mut priv_data).expect("Unable to read");
    let (new_d, new_nn) = key_byte_to_numbers(priv_data);
    let decrypted_message = decrypt(new_d, new_nn, encrypted_message);
    println!("Decrypted Message: {:?}", decrypted_message);

}


fn gcd(mut a: i32, mut b: i32) -> i32{
    while b != 0 {
        std::mem::swap(&mut b, &mut a);
        b %= a;
    }
    a
}


fn write_to_file(mut file: File, key: &i32, n: &i32) {
    file.write_all(key.to_string().as_bytes()).expect("Unable to write");
    file.write_all(" ".as_bytes()).expect("Unable to write");
    file.write_all(n.to_string().as_bytes()).expect("Unable to write");
}

fn key_byte_to_numbers(data: String) -> (i32, i32){
    let key: i32;
    let n: i32;
    let mut f = String::new();
    let mut l = String::new();
    let mut index = 0;
    for i in data.chars() {
        if i.to_string().as_bytes() == " ".as_bytes() {
            index += 1;
            break
        }
        f.push(i);
        index += 1;
    }
    l.push_str(&data[index..]);
    key = f.parse().unwrap();
    n = l.parse().unwrap();
    (key, n)
}

fn encrypt(e: i32, n: i32, message: &str) -> Vec<i64>{
    let mut encrypted_message: Vec<i64> = vec![];
    for i in message.bytes() {
        encrypted_message.push((((i as i64).pow(e as u32)) as i64) % n as i64);
    }
    encrypted_message
}

fn decrypt(d: i32, n: i32, message: Vec<i64>) -> String{
    let mut decrypted_message: String = String::new();
    for i in message {
        let decrypt_letter = (i.pow(d as u32)) % n as i64;
        println!("{}", decrypt_letter);
    }
    decrypted_message
}