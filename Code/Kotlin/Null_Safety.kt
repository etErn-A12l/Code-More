fun main() {
    // Null Safety
    // var name: String = "Sreejan"
    // println(name.length)

    // Safe call Operator ?.
    var name: String? = null
    println(name?.length)

    // Elvis operator ?:
    println(name?.length ?: 0)
}
