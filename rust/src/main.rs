fn main() {
    let camset_filename: String = std::env::args()
        .nth(1)
        .expect("No Camset filename received");

    let camset_file_as_bytes: Vec<u8> = std::fs::read(camset_filename).unwrap();

    // First 4 bytes are the "Make", 5th byte is exclamation mark, 6th byte through 15th byte are 'Model'
    let camera_make = std::str::from_utf8(&camset_file_as_bytes[0..4])
        .expect("Invalid sequence at start of file, couldn't decode camera make");
    let camera_model = std::str::from_utf8(&camset_file_as_bytes[5..14])
        .expect("Invalid sequence in file, can't determine camera model");

    println!("Camera Make: {}", camera_make);
    println!("Camera Model: {}", camera_model);

    // Date starts at byte 21, goes for 13 bytes, ending through byte 34
    let file_created_date = std::str::from_utf8(&camset_file_as_bytes[21..35])
        .expect("Invalid sequence in file, can't determine date camset file was created");

    println!("File created on date: {}", file_created_date);

    // Camset name is usually in the form CAMSETxy.DAT
    // where 'xy' is a 2-digit number (I'm not 100% sure it's always like this,
    // but in all the files I've seen its like that)
    // Name starts at byte 40, goes for 12 bytes, through byte 52
    let camset_name = std::str::from_utf8(&camset_file_as_bytes[40..53])
        .expect("Invalid sequence in file, can't determine camset name");

    println!("Camset Name: {}", camset_name);

    // When the camera saves images, it has the option of using a prefix (like 'DSC' or 'A7R'),
    // this string is that prefix -- it's always limited to 3 characters
    // Starts at byte 2860, on A7R platform -- tested with A7R4
    // On A9 (which A9 models exactly?), it starts at 2760 instead
    let prefix_start_idx: usize;

    if camera_model.starts_with("ILCE-9M") {
        prefix_start_idx = 2760;
    } else {
        prefix_start_idx = 2860;
    }

    let saved_image_filename_prefix =
        std::str::from_utf8(&camset_file_as_bytes[prefix_start_idx..prefix_start_idx + 4])
            .expect("Invalid sequence in file, can't determine image filename prefix");

    println!(
        "Saved image filename prefix: {}",
        saved_image_filename_prefix
    );
}
