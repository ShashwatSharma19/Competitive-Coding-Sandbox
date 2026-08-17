import pandas as pd

def total_time(employees: pd.DataFrame) -> pd.DataFrame:
    employees['time_spent'] = employees['out_time']-employees['in_time']
    result = employees.groupby(['event_day', 'emp_id'], as_index=False)['time_spent'].sum()
    result = result.rename(columns={'event_day':'day', 'time_spent': 'total_time'})
    result = result.sort_values(['day', 'emp_id']).reset_index(drop=True)
    return result