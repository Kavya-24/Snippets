// program to calculate simple factorial using recursion

#![allow(unused)]
#![allow(unused_imports)]

use std::io;
use std::io::Write;

fn main(){
    
    let mut str_inp =  String::new();
    let mut num:i32 ;
    let mut fact:i32;

    print!("Enter the number you would like to compute factorial of : ");

    io::stdout().flush().unwrap();

    io::stdin()
        .read_line(&mut str_inp)
        .expect("Input error");
        
    num = str_inp.trim().parse().expect("Input not an integer");

    println!("calculating the factorial of {}" , num);
    fact = factorial(num);
    println!("The factorial is {}" , fact);

}

fn factorial(num: i32)->i32{
    if(num < 1){
        return 1;
    }
    return num*factorial(num-1);
}
