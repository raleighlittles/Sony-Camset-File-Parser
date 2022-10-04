
fn main() {

    let camset_filename : String = std::env::args().nth(1).expect("No Camset filename received");

    let camset_file_as_bytes : Vec<u8> = std::fs::read(camset_filename).unwrap();

    // First 4 bytes are the "Make", 5th byte is exclamation mark, 6th byte through 15th byte are 'Model'
    let camera_make = std::str::from_utf8(&camset_file_as_bytes[0..4]).expect("Invalid sequence at start of file, couldn't decode camera make");
    let camera_model = std::str::from_utf8(&camset_file_as_bytes[5..14]).expect("Invalid sequence in file, can't determine camera model");
    println!("Camera Make: {} Camera Model: {}", camera_make, camera_model);
}
