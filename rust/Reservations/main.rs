mod funcs;
mod utils;
use std::collections::HashMap;
fn main() {
    let mut reservation_map: HashMap<u8, utils::Reservation> = HashMap::new();
    let mut id: u8 = 1;
    println!("Good morning!");
    loop {
        println!(
            "
    \nWhat would you like to do?
    \n  (1) Make a reservation
    \n  (2) Cancel a previous reservation
    \n  (3) See available reservations
    \n  (4) Exit\n"
        );
        let mut option1 = String::new();
        std::io::stdin().read_line(&mut option1).expect("error");
        let option: u8 = option1.trim().parse().unwrap();
        if option == 1 {
            reservation_map.insert(funcs::id(id), funcs::new_reservation());
            println!("Your reservation ID is: {}", id)
        } else if option == 2 {
            funcs::cancel_reservation(&mut reservation_map);
        } else if option == 3 {
            funcs::see_reservations(&mut reservation_map);
        } else if option == 4 {
            funcs::exit_code();
        } else {
            println!("Invalid option, try again");
        }
    }
}
