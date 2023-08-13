import React from "react";

function Counter(props) {
  function getCount() {
    return props.value === 0 ? "Zero" : props.value;
  }

  function getCountClass() {
    let cl = "text-white py-2 mr-4 rounded-lg";
    if (props.value !== 0) {
      cl += " bg-blue-500 px-7";
    } else {
      cl += " bg-yellow-500 px-4 text-black font-semibold";
    }
    return cl;
  }

  return (
    <div>
      <div className="flex mb-4 my-4 mx-4">
        <h2 className={getCountClass()}>{getCount()}</h2>
        <button
          onClick={() => props.onIncrement(props.id)}
          className="bg-pink-500 hover:bg-pink-700 text-white py-2 px-4 mx-2 rounded-lg"
        >
          +
        </button>
        <button
          disabled={props.value === 0}
          onClick={() => props.onDecrement(props.id)}
          className="bg-pink-500 hover:bg-pink-700 disabled:bg-gray-400 text-white py-2 px-4 rounded-lg"
        >
          -
        </button>
        <button
          onClick={props.onDelete}
          className="bg-red-600 hover:bg-red-700 text-white py-2 px-4 ml-8 mx-2 rounded-lg"
        >
          Delete
        </button>
      </div>
    </div>
  );
}

export default Counter;
