fun main() {

    // If Else conditioning

    if (2 > 1) {
        println("Condition is True af")
    } else {
        println("Condition is False af")
    }

    if (5 > 2) println("Jhinku !") else println("Nonku !")

    var disco = 0

    disco = if (89 > 0) 90 else 45
    println(disco)

    // When Conditioning {Similar with switch Function}

    val rating = 4
    val result =
            when (rating) {
                5 -> "High"
                4, 3 -> "Good"
                2, 1 -> "Moderate"
                else -> {
                    println("No Rating")
                    "Zero"
                }
            }
    println("The rating is $result")
}
