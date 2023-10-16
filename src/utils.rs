use chrono::*;
use std::num::ParseIntError;
pub fn numinput() -> u32 {
    loop {
        let mut return_var = String::new();
        std::io::stdin().read_line(&mut return_var).expect("Error");
        let return_var: Result<u32, ParseIntError> = return_var.trim().parse();
        match return_var {
            Ok(return_var) => return return_var,
            Err(ParseIntError) => println!("Please enter a valid number."),
        }
    }
}
#[derive(Debug)]
pub enum ErrorList {
    InvalidOpt,
    InvalidAge,
    TooMany,
    InvalidDate,
}
#[derive(Debug)]
pub struct Reservation {
    pub name: String,
    pub age: u8,
    pub people: u8,
    pub date: Result<DateTime<Utc>, ErrorList>,
}
impl Reservation {
    pub fn date() -> Result<DateTime<Utc>, ErrorList> {
        println!("When is your reservation due?");
        loop {
            let local = Local::now();
            let date = Reservation::get_date();
            let valid_date: Result<DateTime<Utc>, ErrorList> = Ok(date.clone());
            if date.timestamp() >= local.timestamp() {
                match valid_date {
                    Ok(valid_date) => return Ok(valid_date),
                    Err(ErrorList::InvalidDate) => {
                        println!("Error, Invalid Date. Please try again. ")
                    }
                    _ => println!("Error, Invalid Date. Please try again. "),
                };
            } else {
                println!("Error, Invalid Date. Please try again. ");
                continue;
            }
        }
    }
    pub fn get_date() -> DateTime<Utc> {
        loop {
            println!("Enter the date (yyyy, mm, dd). ");
            let yyyy = numinput();
            let mm = numinput();
            let dd = numinput();
            println!("At what time? (hr, min). ");
            let hr = numinput();
            let min = numinput();
            let date: LocalResult<DateTime<Utc>> =
                Utc.with_ymd_and_hms(yyyy.try_into().unwrap(), mm, dd, hr, min, 0);
            match date {
                LocalResult::None => println!("Invalid date, try again."),
                Single => return date.unwrap(),
            };
        }
    }
}
