fun main() {

    // Type conversions
    val a: Int = 50
    // val b: Long = a
    val b: Long = a.toLong()
    println(b)

    // Type Check
    val name: Any = "Sreejan"
    if (name is String) {
        println(name.length)
    }

    val name1: String = name as String
    println(name1)
}
