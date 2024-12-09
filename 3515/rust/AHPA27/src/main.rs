use std::rc::Rc;

fn main() {
    let name:String = String::from("Bob Johnson");
    let name_ptr:&String = &name;
    println!("name_ptr = {}", *name_ptr);
    let name_remote = Box::new(name);
    println!("name_remote = {}", *name_remote);
    let name2 = Rc::new(String::from("Ann Majors"));
    let name3 = name2.clone();
    let name4 = name2.clone();
    println!("{} {} {}", *name2, *name3, *name4);
}
