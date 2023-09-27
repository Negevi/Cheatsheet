use rand::Rng;
pub struct Road {
    pub signal_r1: State,
    pub signal_r2: State,
    pub qnt_r1: Vec<Cars>,
    pub qnt_r2: Vec<Cars>,
}
#[derive(Debug)]
pub struct Cars {
    drunk: Option<bool>,
    passengers: u8,
    num: i32,
}
#[derive(Debug)]
pub enum State {
    Green,
    Yellow,
    Red,
}
impl Road {
    pub fn def_road(num1: i32, num2: i32) -> Road {
        let road = Road {
            signal_r1: State::Green,
            signal_r2: State::Red,
            qnt_r1: Cars::def_cars(num1),
            qnt_r2: Cars::def_cars(num2),
        };
        return road;
    }
}
impl Cars {
    pub fn def_cars(mut num: i32) -> Vec<Cars> {
        let mut vec_cars: Vec<Cars> = Vec::new();
        let mut qnt_cars: u8 = rand::thread_rng().gen_range(1..=4);
        while qnt_cars != 0 {
            let car: Cars = Cars {
                passengers: rand::thread_rng().gen_range(1..=5), // note that this includes the driver
                drunk: Some(Cars::drunk_def()),
                num: num,
            };
            num += 1;
            vec_cars.push(car);
            qnt_cars -= 1;
        }
        return vec_cars;
    }
    pub fn drunk_def() -> bool {
        let drunk_chance: i32 = rand::thread_rng().gen_range(1..=20);
        if drunk_chance == 1 {
            return true;
        } else {
            return false;
        }
    }
    pub fn add_cars(mut death: bool, mut num: i32) -> Vec<Cars> {
        let mut qnt_rx = Vec::new();
        let mut qnt_cars: u8 = rand::thread_rng().gen_range(1..=3);
        while qnt_cars != 0 {
            let car: Cars = Cars {
                passengers: rand::thread_rng().gen_range(1..=5), // note that this includes the driver
                drunk: Some(Cars::drunk_def()),
                num: num,
            };
            if car.drunk == Some(true) {
                death = true;
            } else {
                continue;
            }
            qnt_rx.push(car);
            num += 1;
            qnt_cars -= 1;
        }
        println!("{:?}", qnt_rx);
        return qnt_rx;
    }
}
impl State {
    pub fn change_state(signal: State) -> State {
        match signal {
            State::Green => State::Yellow,
            State::Yellow => State::Red,
            State::Red => State::Green,
        }
    }
}

// rand::thread_rng().gen_range(1..=4)
