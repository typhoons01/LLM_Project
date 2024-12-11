# LLM_Project
Project Submission for Group-2 in the course CS F441-Selected Topics in Computer Science (2023-24)(Sem-II)

## Running the code
### Clone repo
```
git clone git@github.com:typhoons01/LLM_Project.git
$ cd LLM_Project
```

### Create an environment and install dependencies
#### Mac/Linux/WSL
```
$ python3 -m venv project_env
$ source project_env/bin/activate
$ pip install -r requirements.txt
```
#### Windows Powershell
```
PS> python3 -m venv project_env
PS> Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope Process
PS> project_env\scripts\activate
PS> pip install -r requirements.txt
```
### Setting up env variables
Briefly going over how to set up environment variables. You can also 
use a `.env` file with `python-dotenv` library.
#### Mac/Linux/WSL
```
$ export API_ENV_VAR="your-api-key-here"
```
#### Windows Powershell
```
PS> $env:API_ENV_VAR = "your-api-key-here"
```
### Set OpenAI API key
* If you don't have an OpenAI API key, you can sign up [here](https://openai.com/index/openai-api/).
*  Set `OPENAI_API_KEY` in your environment 