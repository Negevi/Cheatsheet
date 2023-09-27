mod utils;
use crate::utils::*;
use std::{thread, time::Duration};
fn main() {
    println!("Many cars!! wooww");
    let death = false;
    let mut tick = 0;
    let num1 = 1;
    let num2 = 1;
    let mut road = Road::def_road(num1, num2); // note that 1st road is defined as green, 2nd road is defined as red.
    loop {
        thread::sleep(Duration::from_secs(1));
        tick += 1;
        println!("\nTick {}\n", tick);
        let signalprint1: &str = match road.signal_r1 {
            State::Green => "Green",
            State::Yellow => "Yellow",
            State::Red => "Red",
        };
        let signalprint2: &str = match road.signal_r2 {
            State::Green => "Green",
            State::Yellow => "Yellow",
            State::Red => "Red",
        };
        println!(
            "Road 1; Cars: {:?}\nRoad 1; Signal {}.\n",
            road.qnt_r1, signalprint1
        );
        println!(
            "Road 2; Cars: {:?}\nRoad 2; Signal {}.\n",
            road.qnt_r2, signalprint2
        );
        if (tick % 5) == 0 {
            road.signal_r1 = State::change_state(road.signal_r1);
            road.signal_r2 = State::change_state(road.signal_r2);
        } else if (tick % 3) == 0  // modules the 1st road
            && match road.signal_r1 {
                State::Green => true,
                State::Yellow => true,
                State::Red => false,
            } && road.qnt_r1.len() > 0
        {
            road.qnt_r1.remove(0);
        } else if (tick % 3) == 0 // modules the 2nd road
            && match road.signal_r2 {
                State::Green => true,
                State::Yellow => true,
                State::Red => false,
            } && road.qnt_r2.len() > 0
        {
            road.qnt_r2.remove(0);
        } else if (tick % 4) == 0 {
            if (tick % 2) == 0 {
                let mut nvec = Cars::add_cars(death, num1);
                road.qnt_r1.append(&mut nvec)
            } else {
                let mut nvec = Cars::add_cars(death, num2);
                road.qnt_r2.append(&mut nvec)
            };
            if death == true {
                println!("Dont drive drunk kids!");
                std::process::exit(0)
            }
        }
    }
}
