import pandas as pd

def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    df = scores.copy()
    df['rank'] = df['score'].rank(method='dense', ascending=False).astype(int)
    result = df[['score', 'rank']].sort_values('score', ascending=False)
    return result