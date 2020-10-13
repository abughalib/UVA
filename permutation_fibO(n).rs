#[allow(dead_code)]
#[allow(unused)]

fn permutation(n:u32, r:u32)->u32{
  let mut facts: Vec<u32> = Vec::new();
  facts.push(1);
  for i in 1..n+1{
    facts.push(facts[(i-1) as usize]*i);
  }
  return (facts[n as usize]/facts[(n-r) as usize]);
}

fn fib(n: u32)->u32{

  let mut fibs: Vec<u32> = Vec::new();
  fibs.push(0);
  fibs.push(1);
  for i in 2..n+1{
    fibs.push(fibs[(i-1) as usize]+fibs[(i-2) as usize]);
  }
  fibs[n as usize]
}

fn main(){

  println!("Permuation of 10, 2: {}", permutation(10, 0));
  println!("Fibronacci of 10 is: {}", fib(10));


}
