use crate::utils::*;
use std::collections::HashMap;
use std::num::ParseIntError;
pub fn new_reservation() -> Reservation {
    let new_reservation = Reservation {
        name: name(),
        age: age(),
        people: amount().unwrap(),
        date: Reservation::date(),
    };
    println!("Congrats! you have made your reservation");
    return new_reservation;
}
pub fn id(mut id: u8) -> u8 {
    id += 1;
    return id;
}
fn name() -> String {
    println!("In which name will your reservation be made?\n");
    let mut reservation_name = String::new();
    std::io::stdin()
        .read_line(&mut reservation_name)
        .expect("error");
    return reservation_name;
}
fn age() -> u8 {
    println!("How old are you? (18+)\n");
    loop {
        let mut input_age = String::new();
        std::io::stdin().read_line(&mut input_age).expect("Error");
        let age: u8 = input_age.trim().parse().unwrap();
        if age >= 18 && age < 100 {
            return age;
        } else if age < 18 {
            println!("Error: you are too young! You have to be at least 18 to make a reservation.\n Please try again: ");
        } else {
            println!("Error: Invalid Age.")
        }
    }
}
fn amount() -> Result<u8, ParseIntError> {
    println!("Reservation for how many? (Max: 8)\n");
    loop {
        let mut get_amount = String::new();
        std::io::stdin().read_line(&mut get_amount).expect("error");
        let amount: Result<u8, ParseIntError> = get_amount.trim().parse();
        if amount.unwrap().clone() > 8 {
            println!("Ops, too many... Please try again.");
            continue;
        } else {
        }
        match amount {
            Ok(amount) => return Ok(amount),
            Err(ParseIntError) => println!("Invalid number, Try again. (Max 8) "),
        };
    }
}
pub fn see_reservations(reservation_map: &mut HashMap<u8, Reservation>) {
    println!("Map of reservations: \n");
    println!("{:#?}", reservation_map);
}
pub fn exit_code() {
    println!("Now exiting... Have a wonderful day!");
    std::process::exit(0);
}
pub fn cancel_reservation(reservation_map: &mut HashMap<u8, Reservation>) {
    println!("What is your reservation ID?\n");
    let mut get_id = String::new();
    std::io::stdin().read_line(&mut get_id).expect("error");
    let get_id: u8 = get_id.trim().parse().unwrap();
    reservation_map.remove(&get_id);
}
