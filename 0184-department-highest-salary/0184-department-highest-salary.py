import pandas as pd

def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    max_salaries = employee.groupby('departmentId')['salary'].max().reset_index()

    highest_emp = employee.merge(max_salaries, on=['departmentId', 'salary'], how='inner')

    result = highest_emp.merge(department, left_on='departmentId', right_on='id', how='inner')
    result = result[['name_y', 'name_x', 'salary']]
    result.columns = ['Department', 'Employee', 'Salary']
    return result