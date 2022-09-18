fun main() {

    // Declaring an array
    val names = arrayOf("Sreejan", "Rituraj", "Ishani", "Piyali")

    // For Loop Structure 1
    for (name in names) {
        println(name)
    }

    // For Loop Structure 2
    for(i in names.indices) {
        println(names[i])
    }
}
