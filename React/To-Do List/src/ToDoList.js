export default function App() {

  };
  
  document.addEventListener('DOMContentLoaded', function() {
    const myInput = document.getElementById('task-input');
    const addTaskButton = document.getElementsByClassName('add-button');

    addTaskButton.addEventListener('click', function() {

      const addTask = () => {
        var newList = document.createElement('li');
        var task = document.createElement('span');
        var deleteTaskButton = document.createElement('button');
        var inputValue = myInput.value;

        newList.classList.add('task-item');
        task.textContent = inputValue;
        deleteButton.textContent = "X";
        deleteButton.classList.add('delete-button');
        deleteButton.onclick = deleteTask;

        newList.appendChild(task);
        newList.appendChild(deleteButton);
      };
    });

    deleteTaskButton.addEventListener('click', function() {

      const deleteTask = () => {
        var taskToRemove = event.target.parentNode; 
        taskToRemove.remove();
        task.remove();
        deleteButton.remove();
      };
  });
  

  return (
    <div className="container">
      <h1>To-Do List</h1>

      <div className="input-group">
        <input id="task-input" type="text" placeholder="Enter a task" />
        <button className="add-button" type="submit" onClick={addTask}>Add</button>
      </div>

      <ul>
        <li className="task-item">
          <span>Wash the dishes</span>
          <button className="delete-button" onClick={() => deleteTask(index)}>X</button>
      </li>
      </ul>
    </div>

    );
  });
