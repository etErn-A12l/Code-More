import React, { useState } from "react";
import Counter from "./counter";
import Navbar from "../Navbar";

function Counters() {
  // const numberOfCounters = 4; // Change this to the desired number of counters

  // const counterComponents = Array.from(
  //   { length: numberOfCounters },
  //   (_, index) => <Counter key={index} />
  // );

  // return <div>{counterComponents}</div>;

  const [counters, setCounters] = useState([0, 0, 0, 0]);

  function getTotal() {
    // let total = 0;
    // for (let i = 0; i < counters.length; i++) {
    //   total += counters[i];
    // }
    // return total;
    return counters.reduce((total, currentValue) => total + currentValue, 0);
  }

  function increaseValue(id) {
    // Create a new array with updated counter value
    const updatedCounters = counters.map((value, index) =>
      index === id ? value + 1 : value
    );
    // Update the state to trigger a re-render
    setCounters(updatedCounters);
  }

  function decreaseValue(id) {
    const updatedCounters = counters.map((value, index) =>
      index === id ? value - 1 : value
    );
    setCounters(updatedCounters);
  }

  function deleteCounter(id) {
    const updatedCounters = counters.filter((_, index) => index !== id);
    setCounters(updatedCounters);
  }

  function addCounter() {
    setCounters([...counters, 0]);
  }

  return (
    <div>
      <Navbar total={getTotal()} />
      <div className="ml-10">
        <button
          onClick={addCounter}
          className=" bg-green-600 mx-4 px-3 py-2 text-white rounded-lg"
        >
          Add +
        </button>

        {counters.map((value, index) => (
          <Counter
            key={index}
            value={value}
            onIncrement={() => increaseValue(index)}
            onDecrement={() => decreaseValue(index)}
            onDelete={() => deleteCounter(index)}
          />
        ))}
      </div>
    </div>
  );
}

export default Counters;
